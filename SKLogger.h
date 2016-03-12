//
// SKLogger.h
//
// Copyright (c) 2016 Sachin Kesiraju
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef SKLogger_h
#define SKLogger_h

#define SKObjDetail(var) __getObjDetail(@encode(__typeof__(var)), (var))

#define PRINT(x, ...) printf("%s", [[NSString stringWithFormat:x, ##__VA_ARGS__] UTF8String])
#define GET_MACRO(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, NAME, ...) NAME

#define LOG0() PRINT(@"")
#define LOG1(x) PRINT(@"%@", SKObjDetail(x))
#define LOG2(x,...) { \
    LOG1(x); \
    LOG1(__VA_ARGS__); \
}
#define LOG3(x,...) { \
    LOG1(x); \
    LOG2(__VA_ARGS__); \
}
#define LOG4(x,...) { \
    LOG1(x); \
    LOG3(__VA_ARGS__); \
}
#define LOG5(x,...) { \
    LOG1(x); \
    LOG4(__VA_ARGS__); \
}
#define LOG6(x,...) { \
    LOG1(x); \
    LOG5(__VA_ARGS__); \
}
#define LOG7(x,...) { \
    LOG1(x); \
    LOG6(__VA_ARGS__); \
}
#define LOG8(x,...) { \
    LOG1(x); \
    LOG7(__VA_ARGS__); \
}
#define LOG9(x,...) { \
    LOG1(x); \
    LOG8(__VA_ARGS__); \
}
#define LOG10(x,...) { \
    LOG1(x); \
    LOG9(__VA_ARGS__); \
}

#ifdef DEBUG
#define SKLog(...) { \
    printf("%s:%d ",__PRETTY_FUNCTION__, __LINE__); \
    GET_MACRO(_0, ##__VA_ARGS__, LOG10, LOG9, LOG8, LOG7, LOG6, LOG5, LOG4, LOG3, LOG2, LOG1, LOG0)(__VA_ARGS__); \
    printf("\n"); \
}
#else
#define SKLog(x, ...)
#endif

static inline id __getObjDetail(const char * type, ...)
{
    va_list variable_param_list;
    va_start(variable_param_list, type);
    
    id object = nil;
    
    if (strcmp(type, @encode(id)) == 0) {
        id param = va_arg(variable_param_list, id);
        object = param;
    }
    else if (strcmp(type, @encode(CGPoint)) == 0) {
        CGPoint param = (CGPoint)va_arg(variable_param_list, CGPoint);
        object = NSStringFromCGPoint(param);
    }
    else if (strcmp(type, @encode(CGSize)) == 0) {
        CGSize param = (CGSize)va_arg(variable_param_list, CGSize);
        object = NSStringFromCGSize(param);
    }
    else if (strcmp(type, @encode(CGVector)) == 0) {
        CGVector param = (CGVector)va_arg(variable_param_list, CGVector);
        object = NSStringFromCGVector(param);
    }
    else if (strcmp(type, @encode(CGRect)) == 0) {
        CGRect param = (CGRect)va_arg(variable_param_list, CGRect);
        object = NSStringFromCGRect(param);
    }
    else if (strcmp(type, @encode(NSRange)) == 0) {
        NSRange param = (NSRange)va_arg(variable_param_list, NSRange);
        object = NSStringFromRange(param);
    }
    else if (strcmp(type, @encode(CFRange)) == 0) {
        CFRange param = (CFRange)va_arg(variable_param_list, CFRange);
        object = [NSValue value:&param withObjCType:type];
    }
    else if (strcmp(type, @encode(CGAffineTransform)) == 0) {
        CGAffineTransform param = (CGAffineTransform)va_arg(variable_param_list, CGAffineTransform);
        object = NSStringFromCGAffineTransform(param);
    }
    else if (strcmp(type, @encode(CATransform3D)) == 0) {
        CATransform3D param = (CATransform3D)va_arg(variable_param_list, CATransform3D);
        object = [NSValue valueWithCATransform3D:param];
    }
    else if (strcmp(type, @encode(SEL)) == 0) {
        SEL param = (SEL)va_arg(variable_param_list, SEL);
        object = NSStringFromSelector(param);
    }
    else if (strcmp(type, @encode(Class)) == 0) {
        Class param = (Class)va_arg(variable_param_list, Class);
        object = NSStringFromClass(param);
    }
    else if (strcmp(type, @encode(short)) == 0) {
        short param = (short)va_arg(variable_param_list, int);
        object = @(param);
    }
    else if (strcmp(type, @encode(int)) == 0) {
        int param = (int)va_arg(variable_param_list, int);
        object = @(param);
    }
    else if (strcmp(type, @encode(long)) == 0) {
        long param = (long)va_arg(variable_param_list, long);
        object = @(param);
    }
    else if (strcmp(type, @encode(long long)) == 0) {
        long long param = (long long)va_arg(variable_param_list, long long);
        object = @(param);
    }
    else if (strcmp(type, @encode(float)) == 0) {
        float param = (float)va_arg(variable_param_list, double);
        object = @(param);
    }
    else if (strcmp(type, @encode(double)) == 0) {
        double param = (double)va_arg(variable_param_list, double);
        object = @(param);
    }
    else if (strcmp(type, @encode(BOOL)) == 0) {
        BOOL param = (BOOL)va_arg(variable_param_list, int);
        object = param ? @"YES" : @"NO";
    }
    else if (strcmp(type, @encode(bool)) == 0) {
        bool param = (bool)va_arg(variable_param_list, int);
        object = param ? @"true" : @"false";
    }
    else if (strcmp(type, @encode(char)) == 0) {
        char param = (char)va_arg(variable_param_list, int);
        object = [NSString stringWithFormat:@"%c", param];
    }
    else if (strcmp(type, @encode(unsigned short)) == 0) {
        unsigned short param = (unsigned short)va_arg(variable_param_list, unsigned int);
        object = @(param);
    }
    else if (strcmp(type, @encode(unsigned int)) == 0) {
        unsigned int param = (unsigned int)va_arg(variable_param_list, unsigned int);
        object = @(param);
    }
    else if (strcmp(type, @encode(unsigned long)) == 0) {
        unsigned long param = (unsigned long)va_arg(variable_param_list, unsigned long);
        object = @(param);
    }
    else if (strcmp(type, @encode(unsigned long long)) == 0) {
        unsigned long long param = (unsigned long long)va_arg(variable_param_list, unsigned long long);
        object = @(param);
    }
    else if (strcmp(type, @encode(unsigned char)) == 0) {
        unsigned char param = (unsigned char)va_arg(variable_param_list, unsigned int);
        object = [NSString stringWithFormat:@"%c", param];
    }
    else {
        void * param = (void *)va_arg(variable_param_list, void *);
        object = [NSString stringWithFormat:@"%p", param];
    }
    
    va_end(variable_param_list);
    
    return object;
}

#endif /* SKLogger_h */
