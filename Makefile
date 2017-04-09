all: mute-noise

mute-noise: mute-noise.c
	cc `pkg-config --cflags ao` -Wall -o mute-noise mute-noise.c `pkg-config --libs ao`
