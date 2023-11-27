#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void checkElfFile(unsigned char *ident);
void printMagicNumber(unsigned char *ident);
void printElfClass(unsigned char *ident);
void printDataEncoding(unsigned char *ident);
void printElfVersion(unsigned char *ident);
void printOSABI(unsigned char *ident);
void printABIVersion(unsigned char *ident);
void printElfType(unsigned int type, unsigned char *ident);
void printEntryPoint(unsigned long int entry, unsigned char *ident);

/**
 * checkElfFile - Checks if the provided file is an ELF file.
 * @ident: The ELF identification header.
 * Return: void
 */
void checkElfFile(unsigned char *ident)
{
    int index;

    for (index = 0; index < 4; index++)
    {
        if (ident[index] != 127 &&
            ident[index] != 'E' &&
            ident[index] != 'L' &&
            ident[index] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

/**
 * printMagicNumber - Prints the magic number of the ELF file.
 * @ident: The ELF identification header.
 * Return: void
 */
void printMagicNumber(unsigned char *ident)
{
    int index;

    printf(" Magic:  ");

    for (index = 0; index < EI_NIDENT; index++)
    {
        printf("%02x", ident[index]);

        if (index == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

/**
 * printElfClass - Prints the ELF class (32-bit or 64-bit) of the ELF file.
 * @ident: The ELF identification header.
 * Return: void
 */
void printElfClass(unsigned char *ident)
{
    printf(" Class:               ");

    switch (ident[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("none\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", ident[EI_CLASS]);
    }
}

/**
 * printDataEncoding - Prints the data encoding (endianness) of the ELF file.
 * @ident: The ELF identification header.
 * Return: void
 */

void printDataEncoding(unsigned char *ident)
{
    printf(" Data:               ");

    switch (ident[EI_DATA])
    {
    case ELFDATANONE:
        printf("none\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", ident[EI_CLASS]);
    }
}

/**
 * printElfVersion - Prints the ELF version of the ELF file.
 * @ident: The ELF identification header.
 * Return: void
 */
void printElfVersion(unsigned char *ident)
{
    printf(" Version:              %d",
           ident[EI_VERSION]);

    switch (ident[EI_VERSION])
    {
    case EV_CURRENT:
        printf(" (current)\n");
        break;
    default:
        printf("\n");
        break;
    }
}

/**
 * printOSABI - Prints the OS/ABI (operating system/ABI) of the ELF file.
 * @ident: The ELF identification header.
 * Return: void
 */

void printOSABI(unsigned char *ident)
{
    printf(" OS/ABI:              ");

    switch (ident[EI_OSABI])
    {
    case ELFOSABI_NONE:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_IRIX:
        printf("UNIX - IRIX\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD\n");
        break;
    case ELFOSABI_TRU64:
        printf("UNIX - TRU64\n");
        break;
    case ELFOSABI_ARM:
        printf("ARM\n");
        break;
    case ELFOSABI_STANDALONE:
        printf("Standalone App\n");
        break;
    default:
        printf("<unknown: %x>\n", ident[EI_OSABI]);
    }
}

/**
 * printABIVersion - Prints the ABI version of the ELF file.
 * @ident: The ELF identification header.
 * Return: void
 */
void printABIVersion(unsigned char *ident)
{
    printf(" ABI Version:            %d\n",
           ident[EI_ABIVERSION]);
}

/**
 * printElfType - Prints the type of the ELF file.
 * @type: The ELF file type.
 * @ident: The ELF identification header.
 * Return: void
 */
void printElfType(unsigned int type, unsigned char *ident)
{
    if (ident[EI_DATA] == ELFDATA2MSB)
        type >>= 8;

    printf(" Type:               ");

    switch (type)
    {
    case ET_NONE:
        printf("NONE (None)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("<unknown: %x>\n", type);
    }
}

/**
 * printEntryPoint - Prints the entry point address of the ELF file.
 * @entry: The entry point address.
 * @ident: The ELF identification header.
 * Return: void
 */

void printEntryPoint(unsigned long int entry, unsigned char *ident)
{
	printf("  Entry point address:               ");

	if (ident[EI_DATA] == ELFDATA2MSB)
	{
		entry = ((entry << 8) & 0xFF00FF00) |
			  ((entry >> 8) & 0xFF00FF);
		entry = (entry << 16) | (entry >> 16);
	}

	if (ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entry);

	else
		printf("%#lx\n", entry);
}

int main(int argc, char *argv[])
{
    int fd;
    ssize_t n;
    unsigned char ident[EI_NIDENT];

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s <elf-file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    n = read(fd, ident, EI_NIDENT);
    if (n == -1)
    {
        perror("read");
	if (close(fd) == -1)
    	{
       	    perror("close");
       	    exit(EXIT_FAILURE);
        }
        exit(EXIT_FAILURE);
    }

    checkElfFile(ident);
    printMagicNumber(ident);
    printElfClass(ident);
    printDataEncoding(ident);
    printElfVersion(ident);
    printOSABI(ident);
    printABIVersion(ident);

    if (close(fd) == -1)
    {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return (0);
}
