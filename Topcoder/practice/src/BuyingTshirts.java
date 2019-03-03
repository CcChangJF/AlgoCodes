public class BuyingTshirts {
    public int meet(int T, int[] Q, int[] P) {
        int sumP = 0;
        int sumQ = 0;
        int meetTimes = 0;
        for (int i = 0; i < Q.length; ++i) {
            sumP += P[i];
            sumQ += Q[i];
            if (sumP >= T && sumQ >= T) {
                ++meetTimes;
            }
            sumP %= T;
            sumQ %= T;
        }
        return meetTimes;
    }

    public static void main(String args[]) {
        int[] Q = new int[]{1, 2, 3, 4, 5};
        int[] P = new int[]{5, 4, 3, 2, 1};
        BuyingTshirts s = new BuyingTshirts();
        System.out.println(s.meet(1, Q, P));
    }
}
