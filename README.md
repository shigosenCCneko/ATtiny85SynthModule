# ATtiny85WaveSynthModule
ATtiny85(45)を使ったMIDIコマンドで制御する
usart接続の波形メモリ簡易音源モジュール
## 仕様
4音ポリフォニックorモノフォニック（コンパイル時に指定)  
サンプリング周波数20KHz  
boaudレート4800

## 接続
シリアル入力 PB3 (PIN2)  
PWM出力     PB4(PIN3)
## コントロール(MIDIコマンド)
MIDIのノートオンオフ実装(0x90,0x80)  
プログラムチェンジ5音 (0xc0)

## PWM出力
出力はカップリングコンデンサを通して、入力先によってはCRのローパスフィルタを通せば良いでしょう。 

