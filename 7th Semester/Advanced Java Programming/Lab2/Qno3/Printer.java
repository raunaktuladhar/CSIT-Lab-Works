public class Printer{
    public synchronized void printDocument(String userName){
        for(int i=0; i<5; i++){
            System.out.println(userName + " is printing " + i);
            try{
                Thread.sleep(500);
            }
            catch(InterruptedException e){
                Thread.currentThread().interrupt();
            }
        }
    }
}