#include <windows.h>

char szText[] = "Hello world.",
szTitle[] = "Information";

main() {
	while (TRUE)
		MessageBox(NULL, szText, szTitle, MB_ICONINFORMATION);
	return EXIT_SUCCESS;
}