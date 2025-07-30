import re

def get_indent(line):
    return len(line) - len(line.lstrip())

def inject_debug_in_blocks(input_file, output_file):
    debug_stmt = 'if (1 == false) { cout << "-1" << endl; }'

    with open(input_file, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    output = []
    block_stack = []  # 记录当前代码块类型和缩进，栈顶为当前块
    block_keywords = ['main', 'for', 'while', 'if', 'else', 'switch']

    # 用来检测函数定义和控制结构行
    func_or_ctrl_pattern = re.compile(
        r'\b(' + '|'.join(block_keywords) + r')\b\s*(\(.*\))?\s*(\{)?'
    )
    
    for line in lines:
        stripped = line.strip()
        indent = ' ' * get_indent(line)

        # 检测是否进入新的代码块
        m = func_or_ctrl_pattern.search(stripped)
        if m:
            keyword = m.group(1)
            has_brace = '{' in stripped
            # 入栈：记录块类型和当前缩进
            block_stack.append((keyword, get_indent(line)))

            output.append(line.rstrip('\n'))
            if has_brace:
                # { 后插入调试语句，缩进+4空格
                output.append(indent + '    ' + debug_stmt)
            continue

        # 判断是否有 {，且不在上面行检测到的那种情况
        if '{' in stripped:
            # 这可能是匿名块或其它块，入栈一个空标记
            block_stack.append(('anonymous', get_indent(line)))
            output.append(line.rstrip('\n'))
            output.append(indent + '    ' + debug_stmt)
            continue

        # 判断是否有 }，在块尾插入语句
        if '}' in stripped:
            # 插入调试语句前面，缩进同当前行
            output.append(indent + debug_stmt)
            output.append(line.rstrip('\n'))

            if block_stack:
                block_stack.pop()
            continue

        # 普通行，直接写
        output.append(line.rstrip('\n'))

    # 写入文件
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write('\n'.join(output) + '\n')

    print(f"✅ 处理完成，生成文件：{output_file}")

if __name__ == "__main__":
    n=1
    while(True): 
        if n>3:
            break
        T='b'+str(n)
        n+=1
        input_file = T+'.cpp'       # 原始C++文件
        output_file = T+'_1.cpp'    # 处理后文件
        inject_debug_in_blocks(input_file, output_file)
