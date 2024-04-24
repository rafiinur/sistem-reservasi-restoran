// Hapus reservasi
void hapus_reservasi(int nomor_reservasi) {
    reservasi *current = head;
    reservasi *prev = NULL;

    int i = 1;
    while (current != NULL) {
        if (i == nomor_reservasi) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            cout << "Reservasi dengan nomor " << nomor_reservasi << " telah dihapus.\n";
            return;
        }
        prev = current;
        current = current->next;
        i++;
    }
    cout << "Reservasi dengan nomor " << nomor_reservasi << " tidak ditemukan.\n";
}

int main()
{
    int pilihan;
    cout << "Masukkan nomor reservasi yang ingin dihapus: ";
    cin >> pilihan;
    if (pilihan != 0)
    {
        hapus_reservasi(pilihan);
        cout << "Daftar Reservasi setelah dihapus:\n";
        daftar_reservasi();
    }

    return 0;
}
