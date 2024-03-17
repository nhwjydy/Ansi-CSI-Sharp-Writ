# ANSI Control Macros

This library provides macros for generating ANSI control character sequences, which can be used to control terminal display effects such as cursor position, text styles, colors, and more.

## How to Use

1. Copy the `Sharp Writ.h` header file into your project.
2. In the places where you need to use ANSI control character sequences, use the macro definitions to generate the corresponding control character sequences.
3. By modifying the macro parameters, you can achieve different terminal display effects based on the usage scenarios of ANSI control character sequences.

## Example

```c
#include <stdio.h>
#include "Sharp Writ.h"

int main() {
    // Set cursor position
    printf(cup, 5, 10);

    // Set text style and color
    printf(Bright);
    printf(FRed);

    // Output text
    printf("Hello, world!");

    // Restore default settings
    printf(Rset);

    return 0;
}
```

## Supported ANSI Control Character Sequences

This library supports various ANSI control character sequences, including but not limited to cursor position control, text style setting, color setting, and more. Please refer to the `Sharp Writ.h` file for specific control character sequences and macro definitions.

## Notes

- Please note that different terminals may have varying degrees of support for ANSI control characters. Therefore, it's important to consider compatibility when using these control characters.
- This library only provides macro definitions for some commonly used ANSI control character sequences. If you have other specific requirements, feel free to modify and expand as needed.

## License

This library is licensed under the [MIT License](LICENSE). Feel free to use and modify.
