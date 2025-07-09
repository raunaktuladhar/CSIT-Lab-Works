public class InsufficientBalanceException extends RuntimeException{
    public InsufficientBalanceException(){
        super(); // parent lai call garnw ko laagi
    }

    public InsufficientBalanceException(String message){
        super(message);
    }
}