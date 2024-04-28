#include <iostream>

struct reservasi {
    int no_reservasi;
    reservasi* next;
    reservasi* prev;
};

reservasi* head = NULL;
reservasi* tail = NULL;

void hapus_reservasi(int nomor_reservasi) {
    reservasi *current = head;
    reservasi *end = tail;

    while (current != NULL) {
        if (current->no_reservasi == nomor_reservasi) {
            if (current == head) {
                head = current->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            }
            if (current == tail) {
                tail = current->prev;
                if (tail != NULL) {
                    tail->next = NULL;
                }
            }
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            delete current;
            std::cout << "Nomor reservasi telah dihapus.\n" << std::endl;
            return;
        }
        current = current->next;
    }

    std::cout << "Nomor reservasi tidak ditemukan.\n" << std::endl;
}

void resv_hapus() {
    int pilihan;
    std::cout << "Masukkan nomor reservasi yang ingin dihapus: ";
    std::cin >> pilihan;
    if (pilihan != 0) {
        hapus_reservasi(pilihan);
        std::cout << "Reservasi setelah dihapus:\n";
    }
}

// int main() {
//     // Contoh penggunaan untuk menambahkan dan menghapus reservasi
//     // Memanggil resv_hapus untuk menghapus reservasi
//     return 0;
// }
