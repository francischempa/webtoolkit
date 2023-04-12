# The program takes two directory paths as command line arguments: an input directory containing HTML files,
# and an output directory to write corresponding C++ files. The program loops over all files in the input directory
# with the extension .html, reads their contents, and writes a new file to the output directory with the same name
# and the extension .cpp. The contents of the HTML file are written as a C++ multiline quote in the new file.
# Overall, the program performs a simple file conversion task, where it converts HTML files to C++ files with the
# same content, enclosed in a multiline quote.

import os
import sys

if len(sys.argv) < 3:
    print("Usage: python3 html_to_cpp.py input_dir output_dir")
    sys.exit(1)

input_dir = sys.argv[1]
output_dir = sys.argv[2]

if not os.path.exists(input_dir):
    print(f"Error: input directory '{input_dir}' does not exist.")
    sys.exit(1)

if not os.path.exists(output_dir):
    os.makedirs(output_dir)

for filename in os.listdir(input_dir):
    if filename.endswith(".html"):
        with open(os.path.join(input_dir, filename), "r") as f:
            contents = f.read()
            output_filename = os.path.join(output_dir, os.path.splitext(filename)[0] + ".h")
            with open(output_filename, "w") as out_f:

                out_f.write("namespace html { auto " + os.path.splitext(filename)[0] + " = ")
                out_f.write('R"(')
                out_f.write(contents)
                out_f.write(')";}')
