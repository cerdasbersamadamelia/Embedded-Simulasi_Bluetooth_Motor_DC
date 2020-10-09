// Program untuk menyalakan dan mematikan motor DC menggunakan bluetooth
int motor = A0; // Menghubungkan motor ke pin D10 arduino uno
int high = 255; // Kondisi high (5V)
int low = 0; // Kondisi Low (0V)
String motion; // Menyimpan string dari user

void setup() { 
  Serial.begin (9600); // Komunikasi Serial
  pinMode (motor, OUTPUT); // Setting motor adalah output
}

void loop() {
  Serial.println("Ketik 'p' untuk memutar, dan 's' untuk berhenti");
  while (Serial.available() == 0){} // Jika user tidak memasukan input apapun, maka tidak dilakukan eksekusi

  motion = Serial.readString(); // Membaca string dari user
  if (motion == "p"){ 
    analogWrite (motor, low); // Motor akan berputar
    Serial.println("Input = p -> motor DC berputar");
    Serial.println(""); // Baris baru
  }

  if (motion == "s"){
    analogWrite (motor, high); // Motor akan berhenti
    Serial.println("Input = s -> motor DC berhenti");
    Serial.println(""); // Baris baru
  }
}
