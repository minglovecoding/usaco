def inject_debug_with_proper_indent(input_path, output_path):
    insert_line = "if -1==0: print(-1)\n"
    if -1==0:
        print(-1)
    def get_indent(line):
        return len(line) - len(line.lstrip(' '))

    with open(input_path, 'r', encoding='utf-8') as infile:
        lines = infile.readlines()

    new_lines = []

    for i, line in enumerate(lines):
        new_lines.append(line)

        stripped = line.strip()
        if stripped == '' or stripped.startswith('#'):
            continue

        base_indent = get_indent(line)

        # 如果该行以冒号结尾，表示下行应当多一层缩进
        if stripped.endswith(':'):
            indent = ' ' * (base_indent + 4)
        else:
            indent = ' ' * base_indent

        new_lines.append(indent + insert_line)

    with open(output_path, 'w', encoding='utf-8') as outfile:
        outfile.writelines(new_lines)

    print(f"✅ 缩进处理完成，新文件已保存为：{output_path}")


# 示例用法
if __name__ == "__main__":
    input_file = "b1.py"         # 要处理的原始 Python 文件
    output_file = "b1_1.py"  # 生成的新文件
    inject_debug_with_proper_indent(input_file, output_file)
