{\rtf1\ansi\ansicpg1252\cocoartf2639
        \cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fmodern\fcharset0 Courier;}
        {\colortbl;\red255\green255\blue255;\red0\green0\blue0;}
        {\*\expandedcolortbl;;\cssrgb\c0\c0\c0;}
        \paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
        \deftab720
        \pard\pardeftab720\partightenfactor0

        \f0\fs26 \cf0 \expnd0\expndtw0\kerning0
        \outl0\strokewidth0 \strokec2 import java.util.Scanner;\
        \
public class Main \{\
static final int N = 100005;\
        \
static int T, n;\
static long c_time, m_time;\
static long[] a = new long[N], b = new long[N], c = new long[N];\
        \
static long find_bottom_c(int i, long ans) \{\
        long ans_l = 0;\
        long ans_r = Math.min(c_time - 1, ans);\
        long sum = a[i] * c_time + b[i] * m_time;\
        while (ans_l <= ans_r) \{\
        long ans_m = (ans_l + ans_r) / 2;\
        if (sum - ans_m * a[i] - Math.min((ans - ans_m), m_time - 1) * b[i] - c[i] <= 0) \{\
        ans_r = ans_m - 1;\
        \} else \{\
        ans_l = ans_m + 1;\
        \}\
        \}\
        return ans_l;\
        \}\
        \
static long find_bottom_m(int i, long ans) \{\
        long ans_l = 0;\
        long ans_r = Math.min(m_time - 1, ans);\
        long sum = a[i] * c_time + b[i] * m_time;\
        while (ans_l <= ans_r) \{\
        long ans_m = (ans_l + ans_r) / 2;\
        if (sum - ans_m * b[i] - Math.min((ans - ans_m), c_time - 1) * a[i] - c[i] <= 0) \{\
        ans_r = ans_m - 1;\
        \} else \{\
        ans_l = ans_m + 1;\
        \}\
        \}\
        return ans_l;\
        \}\
        \
static boolean check(long ans) \{\
        long bottom_c = 0;\
        long bottom_m = 0;\
        for (int i = 0; i < n; ++i) \{\
        if (a[i] >= b[i]) \{\
        bottom_c = Math.max(bottom_c, find_bottom_c(i, ans));\
        \}\
        if (b[i] >= a[i]) \{\
        bottom_m = Math.max(bottom_m, find_bottom_m(i, ans));\
        \}\
        \}\
        if (bottom_c > ans || bottom_c > c_time - 1) \{\
        return false;\
        \}\
        if (bottom_m > ans || bottom_m > m_time - 1) \{\
        return false;\
        \}\
        return bottom_c + bottom_m <= ans;\
        \}\
        \
static long solve() \{\
        long ans_l = 0;\
        long ans_r = c_time + m_time - 2;\
        while (ans_l <= ans_r) \{\
        long ans_m = (ans_l + ans_r) / 2;\
        if (check(ans_m)) \{\
        ans_r = ans_m - 1;\
        \} else \{\
        ans_l = ans_m + 1;\
        \}\
        \}\
        return ans_l;\
        \}\
        \
public static void main(String[] args) \{\
        Scanner scanner = new Scanner(System.in);\
        T = scanner.nextInt();\
        while (T-- > 0) \{\
        n = scanner.nextInt();\
        c_time = scanner.nextLong();\
        m_time = scanner.nextLong();\
        for (int i = 0; i < n; ++i) \{\
        a[i] = scanner.nextLong();\
        b[i] = scanner.nextLong();\
        c[i] = scanner.nextLong();\
        \}\
        System.out.println(solve());\
        \}\
        \}\
        \}\
        }