

object MAIN {
   def main(args:Array[String]){
     // paragraph 8
     def int(x:Int, y: Int): Int = {if (x  == y) y else x* int(x+1, y) }
     println(int(2,5))
     def Cube(x:Int): Int = x*x*x
     def mulC(x:Int, y:Int):Int = { 
       if (x == y) y else Cube(x) * mulC(x+1, y) 
     }
     def MUL(f:Int=>Int, x:Int, y:Int):Int = { 
       if(x == y) f(y) else f(x) * MUL(f,x+1,y)
     }
    //println(MUL(Cube, 1,2))
    //println(MUL(x=>x, 1,4))
    def fac(x:Int): Int = MUL(f=>f, 1, x)
    //println(fac(4))
    //paragraph 9
    def sum(f: Int=>Int)(a:Int, b:Int): Int = {
      def loop(a:Int, acc:Int):Int ={
        if (a == 0) acc else loop(a-1, acc+a)
      }
      loop(b,0)
    }
    //println(sum(x=>x)(1,5))
    
    val g = new Rational(4,6)
    //println(g)
    val k: list = new list(1)
    k.push(2)
    k.push(3)
    
    def search(a:Int, b:list): Int = b.find(a)
    println(search(2,k))
    val s = Lst.Lst(3)
    println(s.number)
    }   
}
// paragraph 14
class Rational(x:Int, y:Int){
  private def gcd(a:Int, b:Int): Int = if (b == 0) a else gcd(b, a%b)
  val number = x
  val denom = y
  val g = gcd(this.number,this.denom)
  
  def addR(a:Rational, b: Rational):Rational = new Rational(
      a.number*b.denom+b.number*a.denom, a.denom* b.denom)
  
  def makestr(a:Int) =  a/g 
  
  def less (that:Rational)=
    number* that.denom< that.number * denom
    
    def max (that: Rational)=
      if (this.less(that)) that else this
  
      override def toString = 
         makestr(number).toString + "/" + makestr(denom).toString
        
      
}