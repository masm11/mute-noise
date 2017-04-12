# mute-noise

## このプログラムは何?

DELL Inspiron 13 7000 Series を使っていますが、sound device が何も音を発して
いない間、「プチ…プチ…」と延々ノイズが発生しています。
不思議なことに、何かを再生している間はこのノイズは消えます。
再生していても、曲の始めや終わりなど、無音部分はやはりノイズが出ます。

そこで、対症療法として、ずっと何か音を再生させることを思いつきました。
気にならない程の小さな「サー」音をずっと流していれば、ノイズは出ないのでは?

簡単にプログラムを書いて試したところ、ノイズは消えました。
それがこのプログラムです。

## インストール方法

```sh
make
```

これで `mute-noise` というプログラムができあがりますので、どこか PATH の
通った場所にコピーしてください。

## 使い方

オプションはありません。

```sh
mute-noise &
```

と実行するだけです。

```
[Desktop Entry]
Name=Mute Noise
Comment=Mutes noise from sound device
Exec=mute-noise
Terminal=false
Type=Application
NoDisplay=true
```

などといったファイルを `~/.config/autostart/` に仕込んでおくと良いでしょう。

## ライセンス

GPLv3 です。

## 作者

Yuuki Harano &lt;masm@masm11.ddo.jp&gt;
