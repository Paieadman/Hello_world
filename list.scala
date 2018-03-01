

class list(x:Int, y:list) {
  var number: Int = x
  var s: list = y
  
  def this(x:Int) = this(x, null)
  def this() = this(0, null)
  
  def IsE(a:list):Boolean = {
    if (this.s == null) true else false
  }
  def push(a:Int): Boolean = {
    if (IsE(this)) {
      this.s = new list(a) 
    return true}
    else s.push(a) 
  }
  def find(a:Int):Int = {
    if(a!=1) {
    if (IsE(this)) 
      return 0
      else
        s.find(a-1)
    }
    else return this.number
  }
}

object Lst{
  def Lst() = new list()
  def Lst(a:Int) = new list(a)
  def List(a:Int, b:Int) = {
    val g = new list(a)
    g.push(b)
  }
}