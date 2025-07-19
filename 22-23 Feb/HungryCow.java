import java.io.*;
import java.util.*;

public class HungryCow {
    static class Section{
        long begin;
        long haybales ;
        Section(long begin, long haybales ){
            this.begin = begin;
            this.haybales  = haybales ;
        }
    }
    static Comparator<Section> comparator = new Comparator<Section>() {
        @Override
        public int compare(Section o1, Section o2) {
            return Long.compare(o1.begin, o2.begin);
        }
    };
    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(f.readLine());
        int N = Integer.parseInt(st.nextToken());
        long T = Long.parseLong(st.nextToken());
        PriorityQueue<Section> pq = new PriorityQueue<>(comparator);
        PriorityQueue<Section> pq2 = new PriorityQueue<>(comparator);
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(f.readLine());
            long d = Long.parseLong(st.nextToken());
            long b = Long.parseLong(st.nextToken());
            pq.add(new Section(d, b));
        }
        while(pq.size() > 1){
            Section s1 = pq.poll();
            Section s2 = pq.poll();
            if(s1.begin + s1.haybales - 1 >= s2.begin){
                s1.haybales  += s2.haybales ;
                pq.add(s1);
            }
            else{
                pq2.add(s1);
                pq.add(s2);
            }
        }
        pq2.add(pq.poll());
        long ans = 0;
        while(!pq2.isEmpty()){
            Section s = pq2.poll();
            if(s.begin <= T && s.haybales >= T) ans += T - s.begin + 1;
            if(T > s.haybales ) ans += s.haybales;
        }
        System.out.println(ans);
    }
}
