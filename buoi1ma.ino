#include <Keypad.h>
int i[5] = { 0, 1, 2, 3, 4 };
const byte soHang = 4, soCot = 4;
char cacPhim[soHang][soCot] = {
  { '1', '2', '3', 'A' }, { '4', '5', '6', 'B' }, { '7', '8', '9', 'C' }, { '*', '0', '#', 'D' }
};
byte chanHang[soHang] = { 9, 8, 7, 6 };
byte chanCot[soCot] = { 5, 4, 3, 2 };
Keypad banPhim = Keypad(makeKeymap(cacPhim), chanHang, chanCot, soHang, soCot);

String maNhap = "";
String maDung = "1738";
String maMoi = "";

void setup() {
  Serial.begin(9600);
}

void loop() {
  char phim = banPhim.getKey();
  if (phim) {
    Serial.println(phim);
    maNhap = maNhap + phim;
    if (maNhap.length() == 4) {
      if (maNhap == maDung) Serial.println("Mo khoa thanh cong");
      else Serial.println("Sai mat khay, thu lai");
      maNhap = "";
    }

    if (phim == '*') {
      while (maMoi.length() < 4) {
          char phim = banPhim.getKey();
          if (phim) {
              Serial.print(phim);
              maMoi = maMoi + phim;
          }
    }
      maDung = maMoi;
      maMoi = "";
      Serial.println(maDung);
    }
  }
}