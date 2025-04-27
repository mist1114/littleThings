#!/usr/bin/env python3
import re
import sys
import os

def clean_c_file(input_file, output_file=None):
    """
    Clean a C file by removing comment blocks, comment lines, and empty lines.
    
    Args:
        input_file (str): Path to the input C file
        output_file (str, optional): Path to the output file. If None, will append "_cleaned" to input filename
    
    Returns:
        str: Path to the output file
    """
    # If no output file specified, create one based on input filename
    if output_file is None:
        base_name, ext = os.path.splitext(input_file)
        output_file = f"{base_name}_cleaned{ext}"
    
    with open(input_file, 'r', encoding='utf-8', errors='replace') as f:
        content = f.read()
    
    # Remove block comments (/* ... */)
    content = re.sub(r'/\*.*?\*/', '', content, flags=re.DOTALL)
    
    # Process line by line to remove line comments and empty lines
    lines = content.split('\n')
    cleaned_lines = []
    
    for line in lines:
        # Remove line comments
        line = re.sub(r'//.*$', '', line)
        
        # Skip empty lines
        if line.strip() == '':
            continue
        
        cleaned_lines.append(line)
    
    # Append the cleaned content to the output file
    with open(output_file, 'a', encoding='utf-8') as f:
        f.write('\n'.join(cleaned_lines))
    
    return output_file

def main():
    if len(sys.argv) < 2:
        print("Usage: python clean_c_code.py <input_file> [output_file]")
        print("Example: python clean_c_code.py Battery485.c")
        return
    
    input_file = sys.argv[1]
    output_file = sys.argv[2] if len(sys.argv) > 2 else None
    
    try:
        result_file = clean_c_file(input_file, output_file)
        print(f"Cleaned file saved to: {result_file}")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()