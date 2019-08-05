****************************************************///STRATEGY\\\******************************************************
1. Strategy:
You use this pattern if you need to dynamically change an algorithm used by an object at run time.
Don’t worry, just watch the video and you’ll get it. The pattern also allows you to eliminate code duplication.
It separates behavior from super and subclasses. It is a super design pattern and is often the first one taught.
- See more at: http://www.newthinktank.com/2012/08/strategy-design-pattern-tutorial/#sthash.kpb6otF3.dpuf


***************************************************///OBSERVER\\\******************************************************
2. Observer:
The Observer pattern is a software design pattern in which an object, called the subject (Publisher),
maintains a list of its dependents, called observers (Subscribers),
and notifies them automatically of any state changes, usually by calling one of their methods.
- See more at: http://www.newthinktank.com/2012/08/observer-design-pattern-tutorial/#sthash.qFhscyOA.dpuf


****************************************************///FACTORY\\\*******************************************************
3. Factory:
You use the Factory design pattern when you want to define the class of an object at runtime.
It also allows you to encapsulate object creation so that you can keep all object creation code in one place.
The Factory pattern is presented in many ways to help you learn.
Refer to the code that follows the video to completely understand it.
- See more at: http://www.newthinktank.com/2012/09/factory-design-pattern-tutorial/#sthash.LGYUChsG.dpuf


************************************************///Abstract Factory\\\**************************************************
4. Abstract Factory:
This is considered a hard pattern to understand,
but I consider it to be a combination of all you have learned previously.
You just need to understand that each step is separated by either a abstract class or an interface.
This makes it possible to make extremely flexible objects. All of the code follows the video and is heavily commented.
- See more at: http://www.newthinktank.com/2012/09/abstract-factory-design-pattern/#sthash.lPGabivT.dpuf


***************************************************///SINGLETON\\\******************************************************
5. Singleton:
The Singleton pattern is both easy to understand as well as useful.
I’ll demonstrate first how to implement the Singleton pattern.
Then I’ll provide and example of its usefulness with a Scrabble example.

Threads can sometimes play havoc with this pattern, so I’ll show you how to avoid those problems.
I’ll also review how to use threads, LinkedLists and more.
- See more at: http://www.newthinktank.com/2012/09/singleton-design-pattern-tutorial/#sthash.uNQ8maeX.dpuf


***************************************************///BUILDER\\\********************************************************
6. Builder:
You use the builder design pattern when you want to have many classes help in the creation of an object.
By having different classes build the object you can then easily create many different types of objects
without being forced to rewrite code. The Builder pattern provides a different way to make complex objects
like you’d make using the Abstract Factory design pattern. All of the code follows the video to help you learn.
- See more at: http://www.newthinktank.com/2012/09/builder-design-pattern-tutorial/#sthash.HeLXs14v.dpuf


**************************************************///PROTOTYPE\\\*******************************************************
7. Prototype:
The Prototype design pattern is used for creating new objects (instances) by cloning (copying) other objects.
It allows for the adding of any subclass instance of a known super class at run time.
It is used when there are numerous potential classes that you want to only use if needed at runtime.
The major benefit of using the Prototype pattern is that it reduces the need for creating
potentially unneeded subclasses. All of the code follows the video to help you learn.
- See more at: http://www.newthinktank.com/2012/09/prototype-design-pattern-tutorial/#sthash.uYY57BrY.dpuf


************************************************///JAVA REFLECTION\\\***************************************************
8. Java Reflection:
Many people are confused by reflection because they think it is a concept or technique.
Java Reflection is an API and as soon as you know that it becomes easy.
The Java Reflection API is used to manipulate classes and everything in a class
including fields, methods, constructors, private data, etc. And, in this tutorial you’ll learn it all!
- See more at: http://www.newthinktank.com/2012/09/java-reflection-video-tutorial/#sthash.4lye7m0z.dpuf


*************************************************///DECORATOR\\\********************************************************
9. Decorator:
The Decorator allows you to modify an object dynamically.
You would use it when you want the capabilities of inheritance with subclasses,
but you need to add functionality at run time. It is more flexible than inheritance.
The Decorator Design Pattern simplifies code because you add functionality using many simple classes.
Also, rather than rewrite old code you can extend it with new code and that is always good.
- See more at: http://www.newthinktank.com/2012/09/decorator-design-pattern-tutorial/#sthash.qFWO1pEU.dpuf


**************************************************///COMMAND\\\*********************************************************
10. Command:
The Command design pattern allows you to store a list of commands for later use.
With it you can store multiple commands in a class to use over and over.
I cover the basic pattern in numerous ways including descriptions, diagrams and code.
We look into executing commands on numerous objects. We also explore how to undo commands.
All of the code follows the video. Between it and the video you should be an expert on the Command Pattern.
- See more at: http://www.newthinktank.com/2012/09/command-design-pattern-tutorial/#sthash.0IlNDF45.dpuf


**************************************************///ADAPTER\\\*********************************************************
11. Adapter:
This is a very easy design pattern to grasp and put into use.
This pattern is used when you want to translate one interface of a class into another interface.
Now, it makes sense that these 2 interfaces are compatible otherwise the pattern may not make sense.
To accomplish this, all you need to do is bridge the differences using our old friend composition again.
Watch the video and look at the code below and you’ll get it.
- See more at: http://www.newthinktank.com/2012/09/adapter-design-pattern-tutorial/#sthash.vRk4lxbt.dpuf


**************************************************///FACADE\\\**********************************************************
12. Facade:
The Facade pattern is extremely easy to understand.
Chances are you have used it already and just didn’t know it.
The Facade pattern basically says that you should simplify your methods so that much of what is done
is in the background. In technical terms you should decouple the client from the sub components needed
to perform an operation.
All of the code that follows the video will fill you in on anything
you don’t catch in the video.
- See more at: http://www.newthinktank.com/2012/09/facade-design-pattern-tutorial/#sthash.nMMTLlKq.dpuf


**************************************************///BRIDGE\\\**********************************************************
13. Bridge:
If you ever wanted to build a group of classes that slowly added functionality from one class to the next,
this is the design pattern for you.
There seems to be a lot of confusion in regards to what constitutes a bridge design pattern
in both books as well as online. In this tutorial I will show you how it was explained to me and the ways in which
I have found it is useful. The code after the video goes into greater detail if you’d like to check that out.
- See more at: http://www.newthinktank.com/2012/10/bridge-design-pattern-tutorial/#sthash.2Njl9Wj5.dpuf


**********************************************///TEMPLATE METHOD\\\*****************************************************
14. Template Method:
It is an extremely easy design pattern to understand and use.
With this pattern, you define a method (algorithm) in an abstract class.
It contains both abstract methods and non-abstract methods.
The subclasses that extend this abstract class then override those methods that don’t make sense
for them to use in the default way. It may sound complicated, but it definitely isn’t. It is also extremely useful.
Look at the code after the video to get a complete understanding quickly.
- See more at: http://www.newthinktank.com/2012/10/template-method-design-pattern-tutorial/#sthash.wDjg9mLC.dpuf


************************************************///ITERATOR\\\**********************************************************
15. Iterator:
The iterator design pattern allows you to access objects that are stored in many different collection types.
You do this by creating a common interface that these classes share.
Then you have them provide you with an iterator that allows you to traverse the objects they contain.
Because they all share a common interface you can treat them polymorphically and eliminate a lot of duplicate code.
The example video will explain how and the code that follows will reenforce the concepts.
- See more at: http://www.newthinktank.com/2012/10/iterator-design-pattern-tutorial/#sthash.fa8yOQFa.dpuf


************************************************///COMPOSITE\\\*********************************************************
16. Composite:
The Composite design pattern is used to structure data into its individual parts
as well as represent the inner workings of every part of a larger object.
The composite pattern also allows you to treat both groups of parts in the same way as you treat
the parts polymorphically. This allows your objects to maximize complexity while also remaining dynamic.
All of the code follows the video to help you learn. It is heavily commented.
- See more at: http://www.newthinktank.com/2012/10/composite-design-pattern-tutorial/#sthash.2t7nlSRc.dpuf


***********************************************///FLYWEIGHT\\\**********************************************************
17. Flyweight:
The flyweight design pattern is used to dramatically increase the speed of your code
when you are using many similar objects. To reduce memory usage the flyweight design pattern shares Objects
that are the same rather than creating new ones. In this tutorial, I’ll create 100,000 rectangles and show you
the difference in speed versus creating unique rectangle objects versus the flyweight design.
The code follows to help you learn.
- See more at: http://www.newthinktank.com/2012/10/flyweight-design-pattern-tutorial/#sthash.oq3IQA5q.dpuf


************************************************///STATE\\\*************************************************************
18. State:
I explain how the state pattern is used by using it to simulate an ATM machine.
I explain how you come to decide on the different states.
I then show you how to design the interface that each state will use.
We think about the methods that are needed for every class that implements the interface then.
All the steps are looked at from many directions and the code below will fill in the gaps.
- See more at: http://www.newthinktank.com/2012/10/state-design-pattern-tutorial/#sthash.EFPdzUFj.dpuf


************************************************///PROXY\\\*************************************************************
19. Proxy:
The Proxy design pattern limits access to just the methods you want made accessible in another class.
It can be used for security reasons, because an Object is intensive to create,
or is accessed from a remote location. You can think of it as a gate keeper that blocks access to another Object.
I demonstrate how the proxy pattern works using some code used in my State Design Pattern Tutorial.
You may want to check that tutorial out before proceeding.
- See more at: http://www.newthinktank.com/2012/10/proxy-design-pattern-tutorial/#sthash.MDAqczX4.dpuf


******************************************///CHAIN OF RESPONSIBILITY\\\*************************************************
20. Chain Of Responsibility:
This pattern has a group of objects that are expected to between them be able to solve a problem.
If the first Object can’t solve it, it passes the data to the next Object in the chain.
In this tutorial, I’ll use it to make the right calculations based off of a String request.
While that is pretty simple the capabilities of this pattern are endless.
The code follows the video to help you learn.
- See more at: http://www.newthinktank.com/2012/10/chain-of-responsibility-design-pattern-tutorial/#sthash.BKA3CTXa.dpuf


***********************************************///INTERPRETER\\\********************************************************
21. Interpreter:
The Interpreter design pattern is ignored by most, but in this tutorial I’ll show you how to do some
cool things with it. In top of that, I’ll also answer all of the recent questions I’ve received about both
Java Reflection and String manipulation. I found you can do pretty great things if you combine reflection
with the interpreter design pattern.
All of the code follows the video and it is heavily commented to help you learn.
- See more at: http://www.newthinktank.com/2012/10/interpreter-design-pattern-tutorial/#sthash.VVXsZCj5.dpuf


************************************************///MEDIATOR\\\**********************************************************
22. Mediator:
The Mediator design pattern is used to handle communication between related objects (Colleagues).
All communication is handled by a Mediator Object and the Colleagues don’t need to know
anything about each other to work together.
The Gang of Four description: Allows loose coupling by encapsulating the way disparate sets of objects
interact and communicate with each other.
Allows for the actions of each object set to vary independently of one another.
- See more at: http://www.newthinktank.com/2012/10/mediator-design-pattern-tutorial/#sthash.SKpvv6kh.dpuf


************************************************///MEMENTO\\\***********************************************************
23. Memento:
The Memento design pattern provides a way to store previous states of an Object easily.
It has 3 main classes. Memento: The basic object that is stored in different states.
Originator: Sets and Gets values from the currently targeted Memento.
Creates new Mementos and assigns current values to them.
Caretaker: Holds an ArrayList that contains all previous versions of the Memento.
It can store and retrieve stored Mementos. All of the code is down below to help you learn.
- See more at: http://www.newthinktank.com/2012/10/memento-design-pattern-tutorial/#sthash.AajoCpNV.dpuf


************************************************///VISITOR\\\***********************************************************
24. Visitor:
The Visitor design pattern allows you to add methods to classes of different types without much altering
to those classes. You can make completely different methods depending on the class used with this pattern.
With both the video below and the code that follows you should be able to start using this pattern in your code easily.
- See more at: http://www.newthinktank.com/2012/11/visitor-design-pattern-tutorial/#sthash.62uvz7li.dpuf