//
//  ViewController.m
//  SKLoggerDemo
//
//  Created by Sachin Kesiraju on 3/11/16.
//  Copyright © 2016 Sachin Kesiraju. All rights reserved.
//

#import "ViewController.h"
#import "SKLogger.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
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
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
