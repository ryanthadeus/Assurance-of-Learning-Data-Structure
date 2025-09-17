Boogle Dictionary – Data Structure Project
## 🚀 Fitur Utama

1. **Release a new slang word** – Menambahkan kata slang baru beserta deskripsi.
2. **Search a slang word** – Mencari slang tertentu dalam dictionary.
3. **View slang words with a prefix** – Menampilkan semua slang yang dimulai dengan awalan tertentu.
4. **View all slang words** – Menampilkan semua slang beserta deskripsinya.
5. **Exit** – Keluar dari program.

## 🛠️ Struktur Data

Program ini menggunakan **TrieNode** yang terdiri dari:

* `children[26]` → pointer untuk setiap huruf alfabet.
* `desc` → deskripsi slang.
* `isEnd` → penanda akhir sebuah kata slang.

## 📂 File

* `boogle.cpp` – file utama program.

## 📖 Cara Menjalankan

1. Compile program:

   ```bash
   gcc boogle.cpp -o boogle
   ```
2. Jalankan:

   ```bash
   ./boogle
   ```

## 📌 Menu Program

* **Menu 1**: Masukkan slang baru (min. 2 karakter, tanpa spasi) dan deskripsinya (min. 2 kata).
* **Menu 2**: Cari slang, tampilkan deskripsi jika ditemukan.
* **Menu 3**: Cari slang berdasarkan prefix.
* **Menu 4**: Cetak semua slang beserta deskripsi.
* **Menu 5**: Keluar dari program.

## 🔍 Contoh Output

```
Hi This is Boogle.
May I help you?
1. Release a new slang word
2. Search a slang word
3. View all slang words starting with a certain prefix word
4. View all slang words
5. Exit
```

## ✨ Catatan

* Program ini menggunakan **rekursi** untuk menampilkan semua slang di dalam Trie.
* Input divalidasi agar slang minimal 2 karakter dan deskripsi minimal 2 kata.
