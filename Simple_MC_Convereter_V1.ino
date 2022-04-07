//ATtiny2313A
//力行5段、抑速5段に対応。11入力をMC53A、MC37Aと同等の6出力に変換する
//書き込み時、ノッチが0でないとエラーを吐く(P1、P2端子がSPI端子と共通のため)
//環境設定ボードマネージャに追加し、ATTinyCoreを導入するhttp://drazzy.com/package_drazzy.com_index.json
//書き込み装置はArduino as ISP 等でICSP端子を用いて直接書込むこと
//ArduinoISPを使用するときは、書き込み装置リストがないため、他のArduino AVR Boards 内のprogrammers.txtから適当にもってくる
/*下記内容
arduinoisp.name=ArduinoISP
arduinoisp.protocol=arduinoisp
arduinoisp.program.tool=avrdude
arduinoisp.program.tool.default=avrdude
arduinoisp.program.extra_params=
 */

/* ノッチ組み合わせ
ノッチ　カム軸段数 抑速 5 4 3 2 1
N  111111
P1 111110
P2 111100
P3 111000
P4 110000
P5 100000

H1 001110
H2 011010
H3 011100
H4 010100
H5 010010
 */

#define P1 16
#define P2 15
#define P3 0
#define P4 1
#define P5 2
#define H1 3
#define H2 4
#define H3 5
#define H4 6
#define H5 7

int notch = 0;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  for (int i = 0 ; i < 8 ; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  pinMode(16, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  for (int i = 8 ; i < 14 ; i++) {
    pinMode(i, OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop() {
  if (!digitalRead(P1)) {
    notch = 1;
    digitalWrite(8, 0); //1カム
    digitalWrite(9, 1); //2カム
    digitalWrite(10, 1); //3カム
    digitalWrite(11, 1); //4カム
    digitalWrite(12, 1); //5カム
    digitalWrite(13, 1); //抑速カム
  } else if (!digitalRead(P2)) {
    notch = 2;
    digitalWrite(8, 0); //1カム
    digitalWrite(9, 0); //2カム
    digitalWrite(10, 1); //3カム
    digitalWrite(11, 1); //4カム
    digitalWrite(12, 1); //5カム
    digitalWrite(13, 1); //抑速カム
  } else if (!digitalRead(P3)) {
    notch = 3;
    digitalWrite(8, 0); //1カム
    digitalWrite(9, 0); //2カム
    digitalWrite(10, 0); //3カム
    digitalWrite(11, 1); //4カム
    digitalWrite(12, 1); //5カム
    digitalWrite(13, 1); //抑速カム
  } else if (!digitalRead(P4)) {
    notch = 4;
    digitalWrite(8, 0); //1カム
    digitalWrite(9, 0); //2カム
    digitalWrite(10, 0); //3カム
    digitalWrite(11, 0); //4カム
    digitalWrite(12, 1); //5カム
    digitalWrite(13, 1); //抑速カム
  } else if (!digitalRead(P5)) {
    notch = 5;
    digitalWrite(8, 0); //1カム
    digitalWrite(9, 0); //2カム
    digitalWrite(10, 0); //3カム
    digitalWrite(11, 0); //4カム
    digitalWrite(12, 0); //5カム
    digitalWrite(13, 1); //抑速カム
  } else if (!digitalRead(H1)) {
    notch = -1;
    digitalWrite(8, 0); //1カム
    digitalWrite(9, 1); //2カム
    digitalWrite(10, 1); //3カム
    digitalWrite(11, 1); //4カム
    digitalWrite(12, 0); //5カム
    digitalWrite(13, 0); //抑速カム
  } else if (!digitalRead(H2)) {
    notch = -2;
    digitalWrite(8, 0); //1カム
    digitalWrite(9, 1); //2カム
    digitalWrite(10, 0); //3カム
    digitalWrite(11, 1); //4カム
    digitalWrite(12, 1); //5カム
    digitalWrite(13, 0); //抑速カム
  } else if (!digitalRead(H3)) {
    notch = -3;
    digitalWrite(8, 0); //1カム
    digitalWrite(9, 0); //2カム
    digitalWrite(10, 1); //3カム
    digitalWrite(11, 1); //4カム
    digitalWrite(12, 1); //5カム
    digitalWrite(13, 0); //抑速カム
  } else if (!digitalRead(H4)) {
    notch = -4;
    digitalWrite(8, 0); //1カム
    digitalWrite(9, 0); //2カム
    digitalWrite(10, 1); //3カム
    digitalWrite(11, 0); //4カム
    digitalWrite(12, 1); //5カム
    digitalWrite(13, 0); //抑速カム
  } else if (!digitalRead(H5)) {
    notch = -5;
    digitalWrite(8, 0); //1カム
    digitalWrite(9, 1); //2カム
    digitalWrite(10, 0); //3カム
    digitalWrite(11, 0); //4カム
    digitalWrite(12, 1); //5カム
    digitalWrite(13, 0); //抑速カム
  } else {
    if (( notch <= 1 ) && (notch >= -1)) {
      notch = 0;
      digitalWrite(8, 1); //1カム
      digitalWrite(9, 1); //2カム
      digitalWrite(10, 1); //3カム
      digitalWrite(11, 1); //4カム
      digitalWrite(12, 1); //5カム
      digitalWrite(13, 1); //抑速カム
    }
  }
}
