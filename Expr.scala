trait Expr{
 def eval: Int = this match {
  case Number(n) => n
  case Sum(e1, e2) => e1.eval + e2.eval
 }
 
def toString(n: Int) = n.toString
 
 def show(e: Expr): String = e match {
 case Number(n) => toString(n)
 case Sum(e1, e2) => {show(e1) + show(e2)}
}
}
 case class Number(n: Int) extends Expr 
 case class Sum(e1: Expr, e2: Expr) extends Expr

 
 
 object Number {
 def apply(n: Int) = new Number(n)
}
object Sum {
 def apply(e1: Expr, e2: Expr) = new Sum(e1, e2)
}
 
 
 object main{
  def main(args:Array[String]){
  def eval(e: Expr): Int = e match {
 case Number(n) => n
 case Sum(e1, e2) => eval(e1) + eval(e2)
}
  var a=eval(Sum(Number(1), Number(2)))
    println(a)
    
  }
}