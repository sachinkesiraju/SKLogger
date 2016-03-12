# SKLogger

SKLogger is a flexible, lightweight logger that removes the common hassles of the standard NSLog.

<b> SKLog </b>
```
SKLog(@"Logging things ", self.view.frame, intValue, floatValue, [ViewController class], charValue, unsignedLongValue, boolValue, @"like this");
```

<b> NSLog </b>
```
NSLog(@"And not like %@ %i %f %@ %c %llu %i this", NSStringFromCGRect(self.view.frame), intValue, floatValue, NSStringFromClass([ViewController class]), charValue, unsignedLongValue, boolValue);
```

- No more inserting format specifiers in your log
- Log variables in sequence (not all at the end)
- Detailed logs that record where call originates

Streamline your debugging experience

<h1> Installation </h1>

Simply drag the file SKLogger.h into your project and ```#import "SKLogger.h"``` and you're good to go.
<h1> Usage </h1>
After importing SKLogger.h into your current file, begin making all logging calls to SKLog() and not the usual NSLog(). 
Follow the syntax for logging in the example below or play around with the Demo project to get a feel for it.

<b> Source </b>
```
#import "SKLogger.h"

NSString *waveEmoji = @"👋";
SKLog(@"Hi there!", waveEmoji, @"SKLogger is a flexible NSLog replacement");
SKLog(@"* No more inserting %@ signs ", @"* No more adding variables at the end ", @"* No more remembering format specifers");
    
int i = 10;
double d = 3.1415;
char c = ',';
    
SKLog(@"Just like this:", i, c, @" ", d);
    
SKLog(@"It also automatically prints out the class name (", [ViewController class], @") and method (", NSStringFromSelector(_cmd), @") you called the log from")
    
SKLog(@"Print CG structs easier than ever - ", @"Frame:", self.view.frame);
    
NSRange range = NSMakeRange(0, 100);
SKLog(@"Print ranges too ", range);
    
SKLog(@"Just #import \"SKLogger.h\" and you're good to go");
    
BOOL isAwesome = YES;
SKLog(@"Hell ", isAwesome, @"!");
```

<b> Output </b>
```
-[ViewController viewDidLoad]:22 Hi there!👋SKLogger is a flexible NSLog replacement
-[ViewController viewDidLoad]:23 * No more inserting %@ signs * No more adding variables at the end * No more remembering format specifers
-[ViewController viewDidLoad]:29 Just like this:10, 3.1415
-[ViewController viewDidLoad]:31 It also automatically prints out the class name (ViewController) and method (viewDidLoad) you called the log from
-[ViewController viewDidLoad]:33 Print CG structs easier than ever - Frame:{{0, 0}, {375, 667}}
-[ViewController viewDidLoad]:36 Print ranges too {0, 100}
-[ViewController viewDidLoad]:38 Just #import "SKLogger.h" and you're good to go
-[ViewController viewDidLoad]:41 Hell YES!
```

<i> Note: SKLog currently only accepts 10 arguments (comma seperated values) but can easily be expanded if necessary </i>

<h1> Support </h1>

If you have any trouble getting started with SKLogger or have discovered a bug, feel free to reach out to me on Twitter <a href = "https://twitter.com/_sachink"> @_sachink </a> or submit an issue/PR and I'll be sure to get in touch with you right away.

<h1> License </h1> 

SKLogger is available under the MIT License. See the LICENSE for more info.
