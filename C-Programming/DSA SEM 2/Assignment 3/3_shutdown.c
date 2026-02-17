#include <stdio.h>
#include <stdlib.h>

int main() {
  // Ask for user confirmation before shutting down
  char choice;
  printf("Are you sure you want to shut down the computer? (y/n): ");
  scanf(" %c", &choice);

  if (choice == 'y' || choice == 'Y') {
    // Use the system function to execute the shutdown command
    // On macOS/Linux: "sudo shutdown -h now" or similar
    // On Windows: "shutdown /s /t 0"

    printf("Shutting down the computer...\n");

#ifdef _WIN32
    // Windows-specific shutdown command
    system("shutdown /s /t 0");
#elif __APPLE__
    // macOS-specific shutdown command (requires sudo in shell)
    system("sudo shutdown -h now");
#else
    // Linux/Unix-specific shutdown command
    system("shutdown -h now");
#endif
  } else {
    printf("Shutdown cancelled.\n");
  }

  return 0;
}
