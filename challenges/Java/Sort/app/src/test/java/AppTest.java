
import java.util.ArrayList;
import java.util.Arrays;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.util.Collections;
class AppTest {
    @Test void testQS() {

        QuickSort qsUnderTest = new QuickSort();
        ArrayList<String> testLines =new ArrayList<String>( {"B","C","D","E","A"});
        String[] sortedLines = {"A","B","C","D","E"};
        qsUnderTest.sort(testLines,0,testLines.length-1);
        assertTrue(Arrays.equals(testLines,sortedLines));
    }
    @Test void testPartition() {
        QuickSort qsUnderTest = new QuickSort();
        String[] testLines = {"A","D","B","C"};
        String[] pivotLines = {"A","B","C","D"};
        qsUnderTest.partition(testLines,0,testLines.length-1);
        assertTrue(Arrays.equals(testLines,pivotLines));
    }
    @Test void testUniqueOptionChosen() {

    }
    @Test void testQSOptionChosen() {

    }
}
