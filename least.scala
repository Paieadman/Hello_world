 object MAIN {
   def main(args:Array[String]){
     
     def show[T](xs:List[T]): Boolean ={ xs match {
       case Nil => true
       case x::xs => {
         print(x+ " ")
         show(xs)
       }
     }
}
     def last[T](xs: List[T]): T = xs match {
        case List() => throw new Error("последний элемент пустого списка")
 case List(x) => x
 case y :: ys => last(ys)
}
     def concat[T](xs: List[T], ys: List[T]): List[T] = xs match {
 case List() => ys
 case z :: zs => z :: concat(zs, ys)
}
     def init[T](xs: List[T]): List[T] = xs match {
        case List() => throw new Error("инициализация пустого списка")
 case List(x) => Nil
 case y :: ys => y::init(ys)
}
     def removeAt[T](n: Int, xs: List[T]): List[T] ={ xs match{
       case List() => Nil
       case y::ys => n match  { 
         case 0 => removeAt(n-1,ys)
         case n => y::removeAt(n-1,ys)
       }
     }
       
     }
     /*def sqrt(y: Int): Int = y*y
     def squareList(xs: List[Int]): List[Int] = xs match {
 case Nil => this
 case y :: ys => y::squareList(xs)
}*/
   /*  def msort(xs: List[Int]): List[Int] = {
 val n = xs.length/2
 if (n == 0) xs
 else {
  /*def merge(xs: List[Int], ys: List[Int]) : List[Int] =
 xs match {
  case Nil =>ys
  case x :: xs1 =>ys 
  match {
    case Nil =>xs
    case y :: ys1 =>if (x < y) x :: merge(xs1, ys)
     else y :: merge(xs, ys1)
 }*/
}
  def merge(xs:List[Int], ys:List[Int]): (List[Int],List[Int]) = {
   val ss = (xs, ys)
   ss match {
   case (Nil,Nil) => (xs,ys)
   case (x::xs1, y::ys1) => if (x < y) x :: merge(xs1, ys)
     else y :: merge(xs, ys1)}}
   
  val (fst, snd) = xs splitAt n
  merge(msort(fst), msort(snd))
 }
*/
     def sqrtList(xs: List[Double]) =
 xs map (x => x *x)

     val l = List(1,2,3,4,5)
     println(l)
     show(init(l))
     println()
     val m = List(5,4,3,2,1)
     show(l++m)
     println()
     show(removeAt(2,l))
     println()
     //show(squareList(l))
     show(sqrtList(List(1.1,2.2,3.3)))
   }
}