/*  mute-noise - always play white noise.
    Copyright (C) 2017 Yuuki Harano

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <ao/ao.h>

int main(void)
{
    ao_initialize();
    
    int driver_id = ao_default_driver_id();
    
    while (1) {
	ao_sample_format format = {
	    .bits = 16,
	    .rate = 44100,
	    .channels = 2,
	    .byte_format = AO_FMT_LITTLE,
	    .matrix = "L,R",
	};
	
	ao_device *dev = ao_open_live(driver_id, &format, NULL);
	if (dev == NULL) {
	    fprintf(stderr, "ao_open_live() failed. %d", errno);
	    exit(1);
	}
	
	while (1) {
	    static char data[4096];
	    for (int i = 0; i < sizeof data; ) {
		data[i++] = rand() & 0x3f;
		data[i++] = 0;
	    }
	    if (ao_play(dev, data, sizeof data) == 0) {
		fprintf(stderr, "ao_play() failed.");
		break;
	    }
	}
	
	ao_close(dev);
	sleep(1);
    }
    
    return 0;
}
