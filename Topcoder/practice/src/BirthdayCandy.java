public class BirthdayCandy {
    public int mostCandy(int K, int[] candy) {
        int candies = 0;
        for (int i = 0; i < candy.length; ++i) {
            candies = Math.max(candies, candy[i] / (K + 1) + candy[i] % (K + 1));
        }
        return candies;
    }
}
