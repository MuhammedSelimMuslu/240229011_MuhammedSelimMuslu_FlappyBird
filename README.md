# 🐦 YZM104 Programlama II - Flappy Bird

## 👤 Öğrenci Bilgileri

- **Geliştirici:** Muhammed Selim Muslu
- **Öğrenci Numarası:** 240229011
- **Üniversite:** Kocaeli Üniversitesi
- **Bölüm:** Yazılım Mühendisliği

---

## 📖 Proje Açıklaması

Bu proje, modern C++ (C++17) standartları ve **SFML 3** (Simple and Fast Multimedia Library) kullanılarak sıfırdan geliştirilmiş modüler bir sonsuz uçuş (Flappy Bird) oyunudur. 

Geliştirme sürecinin başından sonuna kadar Nesne Yönelimli Programlama (OOP) prensiplerine sadık kalınmış; oyun motorlarının temel taşları olan zaman bazlı fizik hesaplamaları, dinamik bellek yönetimi ve hassas çarpışma algoritmaları projeye başarıyla entegre edilmiştir.

---

## ✨ Geliştirme Süreci ve Teknik Özellikler

Proje, basit bir pencere açma işleminden başlayıp aşama aşama aşağıdaki endüstri standartlarına ulaştırılmıştır:

* **Adil Hitbox (Tıraşlama) Algoritması:** Oyunlarda sıkça yaşanan "görünmez piksele çarpma" sorununu çözmek için `bird.png` ve `pipe.png` görsellerinin etrafındaki şeffaf boşluklar matematiksel olarak kırpılmıştır. SFML 3'ün modern `findIntersection().has_value()` yapısıyla kusursuz bir "Game Over" mekaniği kurulmuştur.
* **Görsel Atmosfer ve Dinamik Ölçeklendirme (Scaling):** Eklenen retro arka plan (`background.png`), pencere çözünürlüğüne dinamik olarak esnetilmiş; üst borular orijinal resmin Y ekseninde ters çevrilmesiyle (negative scaling) bellekte ekstra resim tutmadan oluşturulmuştur.
* **Sıfır Bellek Sızıntısı (Memory Management):** Ekranın solundan dışarı çıkan borular `std::vector` içerisinden anında tespit edilip silinerek RAM şişmesinin (Memory Leak) önüne geçilmiştir.
* **Kare Hızından Bağımsız (Delta-Time) Fizik:** Kuşun yerçekimi, zıplama gücü ve engellerin kayma hızı bilgisayarın FPS'inden bağımsızlaştırılarak her sistemde aynı akıcılık sağlanmıştır.
* **Katmanlı Oyun Durumu (Game State):** Oyun döngüsü, çarpışma anında tamamen donacak ve tek tuşla anında yeniden başlayacak şekilde izole edilmiştir.

---

## 🎮 Kontroller ve Oynanış

Oyuncunun amacı, yerçekimine yenik düşen kuşu ekrana gelen altlı-üstlü boruların arasından geçirerek en yüksek skoru elde etmektir. 

| Tuş / Eylem | Oyun İçi İşlev |
| :--- | :--- |
| **[BOŞLUK] (Space)** | Kuşu havalandırır / Zıplama ivmesi uygular |
| **[BOŞLUK] (Space)** | *(Ölüm Ekranında)* Tüm engelleri siler ve oyunu yeniden başlatır |
| **Pencereyi Kapatma** | SFML döngüsünü kırar, belleği temizler ve güvenli çıkış yapar |

---

## 💻 Kullanılan Teknolojiler

| Teknoloji | Sürüm | Açıklama / Görev |
| :--- | :--- | :--- |
| **C++** | C++17 | Ana oyun mantığı, bellek yönetimi ve OOP mimarisi |
| **SFML** | 3.0 | Grafik çizimleri, pencere yönetimi ve fiziksel çarpışma |
| **Derleyici** | Clang/LLVM | macOS uyumlu C++ kaynak kod derleyicisi |
| **Make** | Güncel | Terminal üzerinden otomatize Makefile derleme sistemi |
| **İşletim Sistemi** | macOS | Geliştirme, test ve derleme ortamı |

---

## 📂 Proje Dosya Yapısı ve Mimari

Kod tabanı, sorumlulukların ayrılması ilkesine göre `Header` ve `Source` olarak bölünmüştür:

```text
FlappyBirdClone/
│
├── README.md
├── CMakeLists.txt
│
├── cpp/
│   ├── oyun.cpp          # Ana tetikleyiciler, Game Loop ve Event takibi
│   ├── bird.cpp          # Fiziksel hesaplamalar ve kuş hitbox ayarları
│   └── pipe.cpp          # Engel geometrisi, ters çevirme ve bellek temizliği
│
├── hpp/
│   ├── bird.hpp          # Bird sınıfı prototipleri
│   └── pipe.hpp          # Pipe sınıfı prototipleri
│
└── build/    
    ├── background.png         # Dinamik ölçeklenen retro arka plan
    ├── bird.png              # Orijinal kuş karakteri
    ├── pipe.png              # Boru engeli
    ├── Makefile              # Derleme otomasyon dosyası
    └── arial.ttf             # Proje mimari dokümantasyonu

```

---

## 🚀 Derleme ve Çalıştırma Adımları

Bu projenin derlenebilmesi için sisteminizde **C++17 derleyicisi** ve **SFML 3.0** kütüphanesinin kurulu olması gerekmektedir. *(macOS için: `brew install sfml`)*

### 1. Derleme (Build) İşlemi

Terminal üzerinden projenin ana dizinine gidin ve eski kalıntıları temizleyip derlemeyi başlatmak için şu komutları çalıştırın:

```bash
make clean
make

```

### 2. Oyunu Başlatma

Derleme başarılı olduktan sonra oluşan çalıştırılabilir dosyayı açın:

```bash
./FlappyBirdClone 

```

> **⚠️ Önemli Not:** Projenin çökmeden çalışabilmesi için `background.png`, `bird.png` ve `pipe.png` dosyalarının çalıştırılabilir dosya ile aynı dizinde bulunduğundan emin olun.

---

## 🔗 Proje İçerikleri

* **GitHub Repository:** https://github.com/MuhammedSelimMuslu/240229011_MuhammedSelimMuslu_FlappyBird
* **Demo Oynanış Videosu:** https://drive.google.com/file/d/1fa33fXyQPzLyOMCrMhbYvKU2xp37iy0l/view?usp=drivesdk

```

```