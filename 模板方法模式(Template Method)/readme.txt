很多事情都是几个固定的步骤完成的，例如到饭馆吃饭会经历点餐-用餐-结账的步骤
这一套步骤可以固定下来作为样板抽象出来，之后每个环节可以有差异，通过多态机制来实现

使用该方式的前提是某个步骤(1个普通成员函数)会固定的调用几个步骤(其他虚成员函数)
这是代码的稳定部分，而每个步骤的具体细节可能不同，留给子类重实现

例子：假设一个游戏人物是战士，他具备三个属性生命值、魔法值和攻击力，他有一个"燃烧"的技能
    "燃烧"会导致战士周边的敌人失去500生命值，自身损失300生命值

第一个版本: 那么这个战士类可以如Warrior_V1.cpp这样写,具备1个成员函数和3个私有属性

现在希望增加一个法师,法师也具备相同的属性和"燃烧"技能，区别是"燃烧"会减少法力值而不是生命值
如果直接增加法师类会导致重复代码出现，所以先抽象战士和法师为战斗者，这个抽象类具备3个属性和"燃烧"技能
"燃烧"技能其实可以抽象为固定的3个步骤，对敌人产生影响，对自身产生影响，播放特效，使用燃烧函数的前提是法力值或者生命值够否则不能使用
所以可以增加3个虚函数和1个普通函数

第二个版本：如Fighter_V1.h这样写，3个虚函数和1个普通成员函数，这4个函数固定被"燃烧"函数调用
之后战士和法师分别继承父类，重实现3个虚函数，在Warrior_V2.h和Mage_V2.h实现
main.cpp使用了这战士和法师类

使用UML图来描述这种关系可见uml.svg




