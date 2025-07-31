import java.util.*;

public class MajorityOpinion {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();

        for (int t = 0; t < T; t++) {
            int N = scanner.nextInt();
            int[] hay = new int[N];

            for (int i = 0; i < N; i++) {
                hay[i] = scanner.nextInt();
            }

            Set<Integer> haySet = new HashSet<>();

            for (int i = 0; i < N - 1; i++) {
                if (hay[i] == hay[i + 1]) {
                    haySet.add(hay[i]);
                }
                if (i < N - 2 && hay[i] == hay[i + 2]) {
                    haySet.add(hay[i]);
                }
            }

            if (haySet.isEmpty()) {
                System.out.println(-1);
                continue;
            }

            List<Integer> hayList = new ArrayList<>(haySet);
            Collections.sort(hayList);

            for (int i = 0; i < hayList.size() - 1; i++) {
                System.out.print(hayList.get(i) + " ");
            }

            System.out.println(hayList.get(hayList.size() - 1));
        }
    }
}
