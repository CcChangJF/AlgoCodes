public class PlayingWithPlanks {
    String canItBeDone(int plankLength, int pieces) {
        return plankLength >= (pieces * (pieces + 1) / 2) ? "possible" : "impossible";
    }
}
