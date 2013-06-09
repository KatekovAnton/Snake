//
//  ViewController.m
//  Snake
//
//  Created by Katekov Anton on 10/18/12.
//
//

#import "ViewController.h"
#import "GLSurface.h"

ViewController      *_g_Controller = nil;

@interface ViewController ()

@end

static int const _kTEiOSMaxTouchesCount = 10;

@implementation ViewController

+ (ViewController *)instance {
    if (!_g_Controller) {
        _g_Controller = [[ViewController alloc] init];
    }
    return _g_Controller;
}

- (void)loadView {
    UIScreen *screen = [UIScreen mainScreen];
    
    self.view = [[GLSurface alloc] initWithFrame:screen.bounds andDepthFormat:_depthFormat andPixelFormat:_pixelFormat];
    _glView = (GLSurface *)self.view;
    
    UISwipeGestureRecognizer* gr = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(onSwipeUp:)];
    gr.numberOfTouchesRequired = 1;
    gr.direction = UISwipeGestureRecognizerDirectionUp;
    gr.delegate = self;
    [self.view addGestureRecognizer:gr];
    
    gr = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(onSwipeDown:)];
    gr.numberOfTouchesRequired = 1;
    gr.direction = UISwipeGestureRecognizerDirectionDown;
    gr.delegate = self;
    [self.view addGestureRecognizer:gr];
    
    gr = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(onSwipeLeft:)];
    gr.numberOfTouchesRequired = 1;
    gr.direction = UISwipeGestureRecognizerDirectionLeft;
    gr.delegate = self;
    [self.view addGestureRecognizer:gr];
    
    gr = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(onSwipeRight:)];
    gr.numberOfTouchesRequired = 1;
    gr.direction = UISwipeGestureRecognizerDirectionRight;
    gr.delegate = self;
    [self.view addGestureRecognizer:gr];
    
    lastTapTime = 0;
}

- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldReceiveTouch:(UITouch *)touch
{
    if(!_pinchDelegate)
        return NO;
    BOOL result = _pinchDelegate->CanStartScreenInput([touch locationInView:self.view].x, [touch locationInView:self.view].y);
    return result;
}

- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gestureRecognizer
{
    if(!_pinchDelegate)
        return NO;
    return _pinchDelegate->CanStartScreenInput([gestureRecognizer locationInView:self.view].x, [gestureRecognizer locationInView:self.view].y);
}

- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer
{
    return YES;
}

- (void)onSwipeUp:(UIPanGestureRecognizer*)gestureRecognizer
{
    if (!_pinchDelegate)
        return;
    
    _pinchDelegate->ProcessAction(0);
}

- (void)onSwipeRight:(UIPanGestureRecognizer*)gestureRecognizer
{
    if (!_pinchDelegate)
        return;
    
    _pinchDelegate->ProcessAction(1);
}

- (void)onSwipeDown:(UIPanGestureRecognizer*)gestureRecognizer
{
    if (!_pinchDelegate)
        return;
    
    _pinchDelegate->ProcessAction(2);
}

- (void)onSwipeLeft:(UIPanGestureRecognizer*)gestureRecognizer
{
    if (!_pinchDelegate)
        return;
    
    _pinchDelegate->ProcessAction(3);
}

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)setPinchDelegate:(DisplayInputDelegate*)delegate
{
    _pinchDelegate = delegate;
}

- (void)setTouchDelegate:(TouchDelagteAdapter)delegate {
    _touchApdater = delegate;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL)shouldAutorotate
{
    return YES;
}

- (NSUInteger)supportedInterfaceOrientations
{
    return UIInterfaceOrientationMaskPortrait;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
{
    return UIInterfaceOrientationIsPortrait(toInterfaceOrientation);
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    _touches = touches;
    _event = event;
    _canhandleTap = YES;
    int ids[_kTEiOSMaxTouchesCount] = {0};
    float xs[_kTEiOSMaxTouchesCount] = {0.0f};
    float ys[_kTEiOSMaxTouchesCount] = {0.0f};
    
    int i = 0;
    for (UITouch *touch in touches) {
        ids[i] = (int)touch;
        xs[i] = [touch locationInView: [touch view]].x * self.view.contentScaleFactor;;
        ys[i] = [touch locationInView: [touch view]].y * self.view.contentScaleFactor;;
        ++i;
    }
    _touchApdater._touchDelegate->handleTouchesBegin(i, ids, xs, ys);
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event {
    int ids[_kTEiOSMaxTouchesCount] = {0};
    float xs[_kTEiOSMaxTouchesCount] = {0.0f};
    float ys[_kTEiOSMaxTouchesCount] = {0.0f};
    
    int i = 0;
    for (UITouch *touch in touches) {
        ids[i] = (int)touch;
        xs[i] = [touch locationInView: [touch view]].x * self.view.contentScaleFactor;;
        ys[i] = [touch locationInView: [touch view]].y * self.view.contentScaleFactor;;
        ++i;
    }
    _touchApdater._touchDelegate->handleTouchesCancel(i, ids, xs, ys);
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
    int ids[_kTEiOSMaxTouchesCount] = {0};
    float xs[_kTEiOSMaxTouchesCount] = {0.0f};
    float ys[_kTEiOSMaxTouchesCount] = {0.0f};
    
    int i = 0;
    for (UITouch *touch in touches) {
        ids[i] = (int)touch;
        xs[i] = [touch locationInView: [touch view]].x * self.view.contentScaleFactor;;
        ys[i] = [touch locationInView: [touch view]].y * self.view.contentScaleFactor;;
        ++i;
    }
    _touchApdater._touchDelegate->handleTouchesEnd(i, ids, xs, ys);
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
    int ids[_kTEiOSMaxTouchesCount] = {0};
    float xs[_kTEiOSMaxTouchesCount] = {0.0f};
    float ys[_kTEiOSMaxTouchesCount] = {0.0f};
    
    int i = 0;
    for (UITouch *touch in touches) {
        ids[i] = (int)touch;
        xs[i] = [touch locationInView: [touch view]].x * self.view.contentScaleFactor;;
        ys[i] = [touch locationInView: [touch view]].y * self.view.contentScaleFactor;;
        ++i;
    }
    _touchApdater._touchDelegate->handleTouchesMove(i, ids, xs, ys);
}

@end
