import java.util.Scanner;
// Other imports go here
// Do NOT change the class name
interface Movable 
{
  public void moveUp();
  public void moveDown();
  public void moveLeft();
  public void moveRight();
}
class MovablePoint implements Movable 
{
  int x, y, xSpeed, ySpeed;
  // Constructor

  // Implement abstract methods declared in the interface Movable
}

class MovableCircle implements Movable 
{
  private MovablePoint center;
  private int radius;
  // Constructor

  // Implement abstract methods declared in the interface Movable
}
