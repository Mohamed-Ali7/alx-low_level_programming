#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>

#define ELF_MAGIC_SIZE        4
#define ELF_CLASS_SIZE        1
#define ELF_DATA_SIZE         1
#define ELF_VERSION_SIZE      1
#define ELF_OSABI_SIZE        1
#define ELF_ABIVERSION_SIZE   1
#define ELF_TYPE_SIZE         2
#define ELF_ENTRYPOINT_SIZE   8

void print_error(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(98);
}

void read_elf_header(int fd, uint8_t buffer[], size_t size) {
    if (read(fd, buffer, size) != (ssize_t)size)
        print_error("Error reading ELF header");
}

void print_magic(const uint8_t buffer[]) {
    printf("ELF Header:\n");
    printf("  Magic:   %02x %02x %02x %02x\n", buffer[0], buffer[1], buffer[2], buffer[3]);
}

int is_elf_file(const uint8_t buffer[]) {
    return (buffer[0] == 0x7f && buffer[1] == 'E' && buffer[2] == 'L' && buffer[3] == 'F');
}

void print_class(const uint8_t buffer[]) {
    int elf_class = buffer[ELF_MAGIC_SIZE + 4] == 2 ? 64 : 32;
    printf("  Class:                             ELF%d\n", elf_class);
}

void print_data(const uint8_t buffer[]) {
    const char* data_encoding = buffer[ELF_MAGIC_SIZE + 5] == 1 ? "2's complement, little endian" :
                                                         "2's complement, big endian";
    printf("  Data:                              %s\n", data_encoding);
}

void print_version(const uint8_t buffer[]) {
    int version = buffer[ELF_MAGIC_SIZE + ELF_CLASS_SIZE + ELF_DATA_SIZE];
    printf("  Version:                           %d (current)\n", version);
}

void print_osabi(const uint8_t buffer[]) {
    uint8_t osabi = buffer[ELF_MAGIC_SIZE + ELF_CLASS_SIZE + ELF_DATA_SIZE + ELF_VERSION_SIZE];
    const char* osabi_name = "<unknown>";

    switch (osabi) {
        case 0x00: osabi_name = "UNIX - System V";      break;
        case 0x01: osabi_name = "UNIX - HP-UX";         break;
        case 0x02: osabi_name = "UNIX - NetBSD";        break;
        case 0x03: osabi_name = "UNIX - Linux";         break;
        case 0x06: osabi_name = "UNIX - Solaris";       break;
        case 0x07: osabi_name = "UNIX - AIX";           break;
        case 0x08: osabi_name = "UNIX - IRIX";          break;
        case 0x09: osabi_name = "UNIX - FreeBSD";       break;
        case 0x0C: osabi_name = "UNIX - OpenBSD";       break;
    }

    printf("  OS/ABI:                            %s\n", osabi_name);
}

void print_abi_version(const uint8_t buffer[]) {
    uint8_t abi_version = buffer[ELF_MAGIC_SIZE + ELF_CLASS_SIZE + ELF_DATA_SIZE +
                                ELF_VERSION_SIZE + ELF_OSABI_SIZE];
    printf("  ABI Version:                       %d\n", abi_version);
}

void print_type(const uint8_t buffer[]) {
    uint16_t type = buffer[ELF_MAGIC_SIZE + ELF_CLASS_SIZE + ELF_DATA_SIZE + ELF_VERSION_SIZE +
                          ELF_OSABI_SIZE + ELF_ABIVERSION_SIZE] |
                   (buffer[ELF_MAGIC_SIZE + ELF_CLASS_SIZE + ELF_DATA_SIZE + ELF_VERSION_SIZE +
                           ELF_OSABI_SIZE + ELF_ABIVERSION_SIZE + 1] << 8);
    const char* type_name = "<unknown>";

    switch (type) {
        case 0x01: type_name = "REL (Relocatable file)";     break;
        case 0x02: type_name = "EXEC (Executable file)";     break;
        case 0x03: type_name = "DYN (Shared object file)";   break;
        case 0x04: type_name = "CORE (Core file)";           break;
    }

    printf("  Type:                              %s\n", type_name);
}

void print_entry_point(const uint8_t buffer[]) {
    uint64_t entry_point = buffer[ELF_MAGIC_SIZE + ELF_CLASS_SIZE + ELF_DATA_SIZE + ELF_VERSION_SIZE +
                                 ELF_OSABI_SIZE + ELF_ABIVERSION_SIZE + ELF_TYPE_SIZE+ ELF_ENTRYPOINT_SIZE] |
                          ((uint64_t)buffer[ELF_MAGIC_SIZE + ELF_CLASS_SIZE + ELF_DATA_SIZE +
                                           ELF_VERSION_SIZE + ELF_OSABI_SIZE + ELF_ABIVERSION_SIZE +
                                           ELF_TYPE_SIZE + 1] << 8) |
                          ((uint64_t)buffer[ELF_MAGIC_SIZE + ELF_CLASS_SIZE + ELF_DATA_SIZE +
                                           ELF_VERSION_SIZE + ELF_OSABI_SIZE + ELF_ABIVERSION_SIZE +
                                           ELF_TYPE_SIZE + 2] << 16) |
                          ((uint64_t)buffer[ELF_MAGIC_SIZE + ELF_CLASS_SIZE + ELF_DATA_SIZE +
                                           ELF_VERSION_SIZE + ELF_OSABI_SIZE + ELF_ABIVERSION_SIZE +
                                           ELF_TYPE_SIZE + 3] << 24) |
                          ((uint64_t)buffer[ELF_MAGIC_SIZE + ELF_CLASS_SIZE + ELF_DATA_SIZE +
                                           ELF_VERSION_SIZE + ELF_OSABI_SIZE + ELF_ABIVERSION_SIZE +
                                           ELF_TYPE_SIZE + 4] << 32) |
                          ((uint64_t)buffer[ELF_MAGIC_SIZE + ELF_CLASS_SIZE + ELF_DATA_SIZE +
                                           ELF_VERSION_SIZE + ELF_OSABI_SIZE + ELF_ABIVERSION_SIZE +
                                           ELF_TYPE_SIZE + 5] << 40) |
                          ((uint64_t)buffer[ELF_MAGIC_SIZE + ELF_CLASS_SIZE + ELF_DATA_SIZE +
                                           ELF_VERSION_SIZE + ELF_OSABI_SIZE + ELF_ABIVERSION_SIZE +
                                           ELF_TYPE_SIZE + 6] << 48) |
                          ((uint64_t)buffer[ELF_MAGIC_SIZE + ELF_CLASS_SIZE + ELF_DATA_SIZE +
                                           ELF_VERSION_SIZE + ELF_OSABI_SIZE + ELF_ABIVERSION_SIZE +
                                           ELF_TYPE_SIZE + 7] << 56);
    printf("  Entry point address:               0x%lx\n", entry_point);
}

void analyze_elf_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
        print_error("Error opening file");

    uint8_t elf_header[64];  // Maximum ELF header size is 64 bytes
    read_elf_header(fd, elf_header, sizeof(elf_header));

    print_magic(elf_header);
    if (!is_elf_file(elf_header))
        print_error("Not a valid ELF file");

    print_class(elf_header);
    print_data(elf_header);
    print_version(elf_header);
    print_osabi(elf_header);
    print_abi_version(elf_header);
    print_type(elf_header);
    print_entry_point(elf_header);

    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    analyze_elf_file(argv[1]);

    return 0;
}
