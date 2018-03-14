

object MaIN {
  def main(args:Array[String]){
  val r = new Poly(1->2.0, 2->4.0, 3->6.0)
  print(r.toString())  
  println()
    val l = new Poly(1->2.0, 2->4.0, 3->6.0)
  print(r.toString())
  println()
  print((r+l).toString())
  println()
  def expr = {
 val x = { print("x"); 1 }
 lazy val y = { print("y"); 2 }
 def z = { print("z"); 3 }
 z + y + x + z + y + x
}
  expr
  println()
  val xs = List(1,2,3,4)
  println(xs.toString())
  val factor = 5
  println(xs map (x => x*factor))
  println(xs filter (x => x%2 == 0))
  
 //val listNumbers = List(1, 2, 3, 4, 5)

//val zeroNumber = 0
//def joinNumbers(a: Int, b: Int): Int = a + b

//println(listNumbers.foldLeft(0)(_+_))
  
def translate(Num:List[Char]) = {
    val mnemonics = Map(
'2' -> "ABC", '3' -> "DEF", '4' -> "GHI", '5' -> "JKL",
'6' -> "MNO", '7' -> "PQRS", '8' -> "TUV", '9' -> "WXYZ")
 def obt(n:Char) = mnemonics(n)
 Num map obt
 def apply() = {
      
    }
  }
  val b = List('2','2','3','4')
  println(translate(b))
  def queens(n: Int) = {
    def isSafe(col:Int,queens:List[Int]):Boolean = {
      if(queens.contains(col)) false else true
    }
 def placeQueens(k: Int): Set[List[Int]] = {
  if (k == 0) Set(List())
  else
   for {
    queens <- placeQueens(k - 1)
    col <- 0 until n
    if isSafe(col, queens)
   } yield col :: queens
 }
 placeQueens(n)
}
 println(queens(4)) 
}
}
class Poly(terms0: Map[Int, Double]) {
 def this(bindings: (Int, Double)*) = this(bindings.toMap)
 val terms = terms0 withDefaultValue 0.0
 def + (other: Poly) = new Poly(terms ++ (other.terms map adjust))
 /*def + (other: Poly) =
 new Poly((other.terms foldLeft 0, )(addTerm))
def addTerm(terms: Map[Int, Double], term: (Int, Double)) ={
   
 }*/
 
 def adjust(term: (Int, Double)): (Int, Double) = {
  val (exp, coeff) = term
  exp -> (coeff + terms(exp))
  }
 override def toString =
  (for ((exp, coeff) <- terms.toList.sorted.reverse)
   yield coeff+"x^"+exp) mkString " + "
}