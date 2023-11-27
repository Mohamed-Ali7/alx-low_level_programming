#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void display_elf_header(const char *filename);

/**
 * main - Entry Point
 * @argc: The number of command line arguments
 * @argv: An array containing the program command line arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(1);
	}

	display_elf_header(argv[1]);

	return (0);
}

/**
 * display_elf_header - Displays the information contained in the ELF header
 * at the start of an ELF file.
 * @filename: Is the file to display
 * Return: void
 */
void display_elf_header(const char *filename)
{
	int fd = open(filename, O_RDONLY), i;
	Elf64_Ehdr header;

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Failed to open file '%s'\n", filename);
		exit(98);
	}
	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Error: Failed to read from file %s\n", filename);
		exit(98);
	}
	if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1
			|| header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: File %s is not an ELF\n", filename);
		exit(98);
	}
	printf("Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header.e_ident[i]);
	}
	printf("\n");
	printf("Class: %d-bit\n", header.e_ident[EI_CLASS] == ELFCLASS32 ? 32 : 64);

	printf("Data: %s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ?
			"2's complement, little endian" : "2's complement, big endian");
	printf("Version: %d\n", header.e_ident[EI_VERSION]);
	printf("OS/ABI: %s\n", header.e_ident[EI_OSABI] == ELFOSABI_SYSV ?
			"UNIX System V ABI" : "Unknown");

	printf("ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);

	printf("Type: %s\n", header.e_type == ET_REL ? "Relocatable" :
			header.e_type == ET_EXEC ? "Executable" :
			header.e_type == ET_DYN ? "Shared object" :
			header.e_type == ET_CORE ? "Core" :
			"Unknown");
	printf("Entry point address: 0x%lx\n", (unsigned long)header.e_entry);
	close(fd);
}
