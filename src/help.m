#ifdef __APPLE__

#import <Foundation/Foundation.h>

// Helper function to get the resource path
char* getResourcePath(const char* filename) {
    NSString *bundlePath = [[NSBundle mainBundle] resourcePath];
    NSString *filePath = [bundlePath stringByAppendingPathComponent:[NSString stringWithUTF8String:filename]];
    return (char *)[filePath UTF8String];
}

#endif
