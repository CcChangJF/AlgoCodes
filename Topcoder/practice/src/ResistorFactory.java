import java.util.ArrayList;
import java.util.HashMap;
import java.util.TreeSet;

public class ResistorFactory {
    private class Command {
        public int a;
        public int b;
        public int type;

        public Command(int a, int b, int t) {
            this.a = a;
            this.b = b;
            this.type = t;
        }
    }

    public int[] construct(long nanoOhms) {
        TreeSet<Long> resistors = new TreeSet<>();
        ArrayList<Long> list = new ArrayList<>();
        HashMap<Long, Command> map = new HashMap<>();
        resistors.add(1000000000L);
        list.add(1000000000L);
        boolean find = false;
        while (true) {
            ArrayList<Long> temp = new ArrayList<>();
            for (int i = 0; i < list.size(); ++i) {
                for (int j = i; j < list.size(); ++j) {
                    Long r1 = list.get(i);
                    Long r2 = list.get(j);
                    Long serial = r1 + r2;
                    Long par = (r1 * r2) / serial;
                    if (!resistors.contains(serial)) {
                        resistors.add(serial);
                        temp.add(serial);
                        map.put(serial, new Command(i, j, 1));
                    }
                    if (!resistors.contains(par)) {
                        resistors.add(par);
                        temp.add(par);
                        map.put(par, new Command(i, j, 2));
                    }
                    if (nanoOhms == serial || nanoOhms == par) {
                        find = true;
                        break;
                    }
                }
                if (find) {
                    break;
                }
            }
            list.addAll(temp);
        }
        TreeSet<Long> toSolve = new TreeSet<>();
        toSolve.add(nanoOhms);
//        ArrayList<Command> res = new ArrayList<>();
        HashMap<Long, Command> res = new HashMap<>();
        while (true) {
            for (Long cur : toSolve) {
                
            }

        }
    }
}
