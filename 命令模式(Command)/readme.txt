这个例子是厨师炒菜的问题

厨师直接做菜，会产生耦合关系，依赖倒转之后是把做菜的动作封装成对象

做菜的动作聚合了厨师，即每个做菜动作内有厨师这个私有属性，厨师做了实际的工作

进一步如果菜特别多，可以用一个列表来维护做菜的动作，实际上就是服务员的功能

服务员可以添加各种菜品，是聚合关系，服务员通知厨师实际上就是调用了所有菜品的执行动作

所以整个依赖倒转的逻辑是：服务员通知做菜，内部所有做菜的动作执行，做菜的动作执行实际调用了厨师的做菜函数


--- 快速理解 ---
命令容器类委维护一个命令列表，提供添加和移除命令的方法，一次性执行所有命令的方法
命令类以命令者类为构造参数，提供执行命令的方法，封装了命令者类的执行方法
命令类可以多态，不同的命令是让命令者做了不同的事情，相应的命令者类也可以多态，命令类可以提供设置不同的命令者方法
CommadList 
    List<Command*> mCommands
    execute() 遍历mCommands执行execute()
    addCommand(Command1),removeCommand(Command2)
Command(Executer*) => Command1,Command2
    setExecuter(Executer*)
    execute() => Executer.execute()
Executer() => Executer1,Executer2
    execute() 
