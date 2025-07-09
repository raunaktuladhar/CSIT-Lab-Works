public class BankAccount {
    private int balance = 1000;

    public void withdraw(int withDrawAmount){
        if(withDrawAmount > balance){
            throw new InsufficientBalanceException("Insufficient balance");
        }

        // The commented parts are optional
        
        else{
            System.out.println("Withdrawing.....");
        }

        balance = balance - withDrawAmount;

        System.out.println("Your remaining balance is " + balance);
    }
}
