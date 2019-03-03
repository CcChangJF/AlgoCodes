import java.util.Arrays;

public class MaximizingGCD {
    private int gcd(int a, int b) {
        if (0 == b) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    private boolean[] mark;
    private int n;
    private int maxFind;
    private int[] nums;

    private void dfs(int cur, int prevPair, int curPair, boolean isPair) {
        if (cur == n) {
            maxFind = Math.max(maxFind, prevPair);
//            System.out.println(" ");
            return;
        } else {
            for (int i = 0; i < n; ++i) {
                if (!mark[i]) {
//                    System.out.print(nums[i] + " ");
                    mark[i] = true;
                    if (cur < 2) {
//                        System.out.println("prev: " + prevPair);
                        dfs(cur + 1, prevPair + nums[i], curPair, isPair);
                    } else {
                        curPair = curPair + nums[i];
                        if (isPair) {
                            prevPair = gcd(prevPair, curPair);
//                            System.out.println("gcd: " + prevPair + ", curPair: " + curPair);
                            curPair = 0;
                            if (prevPair <= maxFind) {
//                                curPair = curPair - nums[i];
                                mark[i] = false;
                                return;
                            }
                        }
                        dfs(cur + 1, prevPair, curPair, !isPair);
                        curPair = curPair - nums[i];
                    }
                    mark[i] = false;
                }
            }
        }
    }

    public int maximumGCDPairing(int[] A) {
        mark = new boolean[A.length];
        Arrays.sort(A);
        for (int i = 0; i < A.length; ++i) {
            mark[i] = false;
        }
        n = A.length;
        maxFind = 0;
        nums = A;
        dfs(0, 0, 0, false);
        return maxFind;
    }

    public static void main(String[] args) {
//        System.out.println(Integer.MAX_VALUE);
//        int[] test = new int[]{16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608};
//        MaximizingGCD m = new MaximizingGCD();
//        System.out.println(m.maximumGCDPairing(test));
        StringBuilder s = new StringBuilder();
        s.append("google");
        String str = new String(s);
        System.out.println("google".equals(str));
    }
}
