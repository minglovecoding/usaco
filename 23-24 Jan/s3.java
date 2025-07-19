import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class s3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();

        Set<Long> uniqueNumbers = new HashSet<>();
        for (int i = 0; i < n; ++i) {
            uniqueNumbers.add(scanner.nextLong());
        }

        long result = 0;
        long mx = Long.MAX_VALUE;
        for (long num : uniqueNumbers) {
            mx = Math.min(mx, num);
        }
        mx /= 4;

        if (uniqueNumbers.size() <= 3) {
            System.out.println(mx * (mx + 1) / 2);
            return;
        }

        for (long i = 1; i <= 1000000; ++i) {
            if (i > mx) break;
            Set<Long> moduloSet = new HashSet<>();
            for (long num : uniqueNumbers) {
                moduloSet.add(num % i);
                if (moduloSet.size() == 4) {
                    break;
                }
            }
            if (moduloSet.size() < 4) {
                result += i;
            }
        }

        if (uniqueNumbers.size() < 1000) {
            Set<Long> factorSet = new HashSet<>();
            for (long num1 : uniqueNumbers) {
                for (long num2 : uniqueNumbers) {
                    if (num2 - num1 > 1000000) {
                        for (long k = 1; k <= 4000; ++k) {
                            if ((num2 - num1) % k == 0) {
                                factorSet.add((num2 - num1) / k);
                            }
                        }
                    }
                }
            }

            for (long factor : factorSet) {
                if (factor > mx) continue;
                if (factor <= 1000000) continue;
                Set<Long> moduloSet = new HashSet<>();
                for (long num : uniqueNumbers) {
                    moduloSet.add(num % factor);
                    if (moduloSet.size() == 4) {
                        break;
                    }
                }
                if (moduloSet.size() < 4) {
                    result += factor;
                }
            }
        }

        System.out.println(result);
    }
}