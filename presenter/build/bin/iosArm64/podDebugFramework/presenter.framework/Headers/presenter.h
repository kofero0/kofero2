#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class PresenterDispatcherProvider, PresenterKotlinx_coroutines_coreCoroutineDispatcher, PresenterModelEventViewTag, PresenterModelEvent, PresenterModelProviderError, PresenterArrow_coreEither<__covariant A, __covariant B>, PresenterKotlinUnit, PresenterModelObj, PresenterArrow_coreIor<__covariant A, __covariant B>, PresenterModelLevel, PresenterKoferoObj, PresenterKotlinException, PresenterInteractorImpl<V, P>, PresenterModelIncorrectCount, PresenterModelMove, PresenterModelCharacter, PresenterGamePresenterImpl, PresenterModelGame, PresenterPresenterImpl<V>, PresenterKotlinAbstractCoroutineContextElement, PresenterKotlinx_coroutines_coreCoroutineDispatcherKey, PresenterKotlinEnumCompanion, PresenterKotlinEnum<E>, PresenterKotlinArray<T>, PresenterModelEventValue, PresenterArrow_coreEitherCompanion, PresenterArrow_coreOption<__covariant A>, PresenterArrow_coreValidated<__covariant E, __covariant A>, PresenterArrow_coreIorCompanion, PresenterKotlinPair<__covariant A, __covariant B>, PresenterKotlinThrowable, PresenterKotlinRuntimeException, PresenterKotlinIllegalStateException, PresenterKotlinAbstractCoroutineContextKey<B, E>, PresenterArrow_coreOptionCompanion, PresenterArrow_coreEval<__covariant A>, PresenterArrow_coreValidatedCompanion, PresenterArrow_coreEvalCompanion, PresenterArrow_coreEvalAlways<__covariant A>, PresenterArrow_coreEvalLater<__covariant A>, PresenterKotlinNothing;

@protocol PresenterStateLogger, PresenterStateProvider, PresenterLoggingProvider, PresenterProvider, PresenterView, PresenterInteractor, PresenterStateReducer, PresenterRouter, PresenterPresenter, PresenterCharacterInteractor, PresenterCharacterPresenter, PresenterCharacterView, PresenterImageProvider, PresenterGameInteractor, PresenterKotlinCoroutineContext, PresenterGameView, PresenterGamePresenter, PresenterModelError, PresenterHomeInteractor, PresenterHomePresenter, PresenterHomeView, PresenterFavoritesProvider, PresenterMovePresenter, PresenterMoveView, PresenterRootPresenter, PresenterRootView, PresenterKotlinCoroutineContextKey, PresenterKotlinCoroutineContextElement, PresenterKotlinContinuation, PresenterKotlinContinuationInterceptor, PresenterKotlinx_coroutines_coreRunnable, PresenterKotlinComparable, PresenterArrow_coreMonoid, PresenterArrow_coreSemigroup, PresenterKotlinIterator;

NS_ASSUME_NONNULL_BEGIN
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
#pragma clang diagnostic ignored "-Wnullability"

#pragma push_macro("_Nullable_result")
#if !__has_feature(nullability_nullable_result)
#undef _Nullable_result
#define _Nullable_result _Nullable
#endif

__attribute__((swift_name("KotlinBase")))
@interface PresenterBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface PresenterBase (PresenterBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface PresenterMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface PresenterMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorPresenterKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface PresenterNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinByte")))
@interface PresenterByte : PresenterNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface PresenterUByte : PresenterNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface PresenterShort : PresenterNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface PresenterUShort : PresenterNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface PresenterInt : PresenterNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface PresenterUInt : PresenterNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface PresenterLong : PresenterNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface PresenterULong : PresenterNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface PresenterFloat : PresenterNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface PresenterDouble : PresenterNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface PresenterBoolean : PresenterNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end


/**
 * @note annotations
 *   kotlinx.coroutines.DelicateCoroutinesApi
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DispatcherProvider")))
@interface PresenterDispatcherProvider : PresenterBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)dispatcherProvider __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PresenterDispatcherProvider *shared __attribute__((swift_name("shared")));
@property (readonly, getter=default) PresenterKotlinx_coroutines_coreCoroutineDispatcher *default_ __attribute__((swift_name("default_")));
@property (readonly) PresenterKotlinx_coroutines_coreCoroutineDispatcher *ui __attribute__((swift_name("ui")));
@end

__attribute__((swift_name("Router")))
@protocol PresenterRouter
@required
- (BOOL)routeToView:(PresenterModelEventViewTag *)view uid:(int32_t)uid __attribute__((swift_name("routeTo(view:uid:)")));
@end

__attribute__((swift_name("StateLogger")))
@protocol PresenterStateLogger
@required
- (NSDictionary<PresenterLong *, PresenterModelEvent *> *)getStateMap __attribute__((swift_name("getStateMap()")));
- (BOOL)logStateUnixTime:(int64_t)unixTime event:(PresenterModelEvent *)event __attribute__((swift_name("logState(unixTime:event:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("StateLoggerImpl")))
@interface PresenterStateLoggerImpl : PresenterBase <PresenterStateLogger>
- (instancetype)initWithStateRepository:(id<PresenterStateProvider>)stateRepository loggingProvider:(id<PresenterLoggingProvider>)loggingProvider __attribute__((swift_name("init(stateRepository:loggingProvider:)"))) __attribute__((objc_designated_initializer));
- (NSDictionary<PresenterLong *, PresenterModelEvent *> *)getStateMap __attribute__((swift_name("getStateMap()")));
- (BOOL)logStateUnixTime:(int64_t)unixTime event:(PresenterModelEvent *)event __attribute__((swift_name("logState(unixTime:event:)")));
@end

__attribute__((swift_name("StateProvider")))
@protocol PresenterStateProvider
@required
- (PresenterArrow_coreEither<PresenterModelProviderError *, NSDictionary<PresenterLong *, PresenterModelEvent *> *> *)get __attribute__((swift_name("get()")));
- (PresenterArrow_coreEither<PresenterModelProviderError *, PresenterKotlinUnit *> *)saveMap:(NSDictionary<PresenterLong *, PresenterModelEvent *> *)map __attribute__((swift_name("save(map:)")));
@end

__attribute__((swift_name("StateReducer")))
@protocol PresenterStateReducer
@required
- (BOOL)authorizeEvent:(PresenterModelEvent *)event stateMap:(NSDictionary<PresenterLong *, PresenterModelEvent *> *)stateMap __attribute__((swift_name("authorize(event:stateMap:)")));
- (PresenterModelEvent *)reduceStateMap:(NSDictionary<PresenterLong *, PresenterModelEvent *> *)stateMap __attribute__((swift_name("reduce(stateMap:)")));
@end

__attribute__((swift_name("Provider")))
@protocol PresenterProvider
@required
- (PresenterArrow_coreIor<PresenterModelProviderError *, NSArray<PresenterModelObj *> *> *)getIds:(NSArray<PresenterInt *> *)ids __attribute__((swift_name("get(ids:)")));
@end

__attribute__((swift_name("FavoritesProvider")))
@protocol PresenterFavoritesProvider <PresenterProvider>
@required
- (PresenterArrow_coreEither<PresenterModelProviderError *, PresenterKotlinUnit *> *)deleteItem:(PresenterModelObj *)item __attribute__((swift_name("delete(item:)")));
- (PresenterArrow_coreEither<PresenterModelProviderError *, PresenterKotlinUnit *> *)saveItem:(PresenterModelObj *)item __attribute__((swift_name("save(item:)")));
@end

__attribute__((swift_name("ImageProvider")))
@protocol PresenterImageProvider
@required
- (PresenterArrow_coreEither<PresenterModelProviderError *, id> *)getUrl:(NSString *)url __attribute__((swift_name("get(url:)")));
@end

__attribute__((swift_name("LoggingProvider")))
@protocol PresenterLoggingProvider
@required
- (void)logLevel:(PresenterModelLevel *)level logTag:(NSString *)logTag message:(NSString *)message __attribute__((swift_name("log(level:logTag:message:)")));
@end

__attribute__((swift_name("Interactor")))
@protocol PresenterInteractor
@required
- (void)setViewView:(id<PresenterView>)view __attribute__((swift_name("setView(view:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
- (void)viewPaused __attribute__((swift_name("viewPaused()")));
- (void)viewResumed __attribute__((swift_name("viewResumed()")));
@end

__attribute__((swift_name("KoferoObj")))
@interface PresenterKoferoObj : PresenterBase
- (instancetype)initWithLoggingProvider:(id<PresenterLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer));
- (void)shutdown __attribute__((swift_name("shutdown()")));
@end

__attribute__((swift_name("InteractorImpl")))
@interface PresenterInteractorImpl<V, P> : PresenterKoferoObj <PresenterInteractor>
- (instancetype)initWithPresenter:(P)presenter stateLogger:(id<PresenterStateLogger>)stateLogger stateReducer:(id<PresenterStateReducer>)stateReducer router:(id<PresenterRouter>)router loggingProvider:(id<PresenterLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(presenter:stateLogger:stateReducer:router:loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithLoggingProvider:(id<PresenterLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (void)setViewView:(V)view __attribute__((swift_name("setView(view:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
- (void)viewPaused __attribute__((swift_name("viewPaused()")));
- (void)viewResumed __attribute__((swift_name("viewResumed()")));
@property id<PresenterRouter> router __attribute__((swift_name("router")));
@end

__attribute__((swift_name("Presenter")))
@protocol PresenterPresenter
@required
- (void)setViewView_:(id<PresenterView>)view __attribute__((swift_name("setView(view_:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
@end

__attribute__((swift_name("PresenterImpl")))
@interface PresenterPresenterImpl<V> : PresenterKoferoObj <PresenterPresenter>
- (instancetype)initWithView:(V _Nullable)view loggingProvider:(id<PresenterLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(view:loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithLoggingProvider:(id<PresenterLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (void)setViewView_:(V)view __attribute__((swift_name("setView(view_:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
@end

__attribute__((swift_name("View")))
@protocol PresenterView
@required
- (void)errorE:(PresenterKotlinException *)e __attribute__((swift_name("error(e:)")));
@end

__attribute__((swift_name("CharacterInteractor")))
@protocol PresenterCharacterInteractor <PresenterInteractor>
@required
- (void)setCharUidUid:(int32_t)uid __attribute__((swift_name("setCharUid(uid:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CharacterInteractorImpl")))
@interface PresenterCharacterInteractorImpl : PresenterInteractorImpl<id<PresenterCharacterView>, id<PresenterCharacterPresenter>> <PresenterCharacterInteractor>
- (instancetype)initWithPresenter:(id<PresenterCharacterPresenter>)presenter stateLogger:(id<PresenterStateLogger>)stateLogger stateReducer:(id<PresenterStateReducer>)stateReducer loggingProvider:(id<PresenterLoggingProvider>)loggingProvider router:(id<PresenterRouter>)router __attribute__((swift_name("init(presenter:stateLogger:stateReducer:loggingProvider:router:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPresenter:(id<PresenterPresenter>)presenter stateLogger:(id<PresenterStateLogger>)stateLogger stateReducer:(id<PresenterStateReducer>)stateReducer router:(id<PresenterRouter>)router loggingProvider:(id<PresenterLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(presenter:stateLogger:stateReducer:router:loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (void)setCharUidUid:(int32_t)uid __attribute__((swift_name("setCharUid(uid:)")));
- (void)setViewView:(id<PresenterCharacterView>)view __attribute__((swift_name("setView(view:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
- (void)viewPaused __attribute__((swift_name("viewPaused()")));
- (void)viewResumed __attribute__((swift_name("viewResumed()")));
@end

__attribute__((swift_name("CharacterPresenter")))
@protocol PresenterCharacterPresenter <PresenterPresenter>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)showCharId:(int32_t)id completionHandler:(void (^)(PresenterArrow_coreEither<PresenterModelProviderError *, PresenterKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("showChar(id:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CharacterPresenterImpl")))
@interface PresenterCharacterPresenterImpl : PresenterBase <PresenterCharacterPresenter>
- (instancetype)initWithCharProvider:(id<PresenterProvider>)charProvider moveProvider:(id<PresenterProvider>)moveProvider imageProvider:(id<PresenterImageProvider>)imageProvider __attribute__((swift_name("init(charProvider:moveProvider:imageProvider:)"))) __attribute__((objc_designated_initializer));
- (void)setViewView_:(id<PresenterCharacterView>)view __attribute__((swift_name("setView(view_:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)showCharId:(int32_t)id completionHandler:(void (^)(PresenterArrow_coreEither<PresenterModelIncorrectCount *, PresenterKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("showChar(id:completionHandler:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
@end

__attribute__((swift_name("CharacterView")))
@protocol PresenterCharacterView <PresenterView>
@required
- (void)displayUrl:(NSString *)url imgBase64:(NSString *)imgBase64 __attribute__((swift_name("display(url:imgBase64:)")));
- (void)displayMoves:(NSArray<PresenterModelMove *> *)moves __attribute__((swift_name("display(moves:)")));
- (void)displayCharacter:(PresenterModelCharacter *)character __attribute__((swift_name("display(character:)")));
- (void)displayNotOnDiskUrl:(NSString *)url __attribute__((swift_name("displayNotOnDisk(url:)")));
@end

__attribute__((swift_name("GameInteractor")))
@protocol PresenterGameInteractor <PresenterInteractor>
@required
- (void)charPressedChar:(PresenterModelCharacter *)char_ __attribute__((swift_name("charPressed(char:)")));
- (void)setGameUidUid:(int32_t)uid __attribute__((swift_name("setGameUid(uid:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GameInteractorImpl")))
@interface PresenterGameInteractorImpl : PresenterInteractorImpl<id<PresenterGameView>, id<PresenterGamePresenter>> <PresenterGameInteractor>
- (instancetype)initWithPresenter:(PresenterGamePresenterImpl *)presenter stateLogger:(id<PresenterStateLogger>)stateLogger stateReducer:(id<PresenterStateReducer>)stateReducer loggingProvider:(id<PresenterLoggingProvider>)loggingProvider router:(id<PresenterRouter>)router context:(id<PresenterKotlinCoroutineContext>)context __attribute__((swift_name("init(presenter:stateLogger:stateReducer:loggingProvider:router:context:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPresenter:(id<PresenterPresenter>)presenter stateLogger:(id<PresenterStateLogger>)stateLogger stateReducer:(id<PresenterStateReducer>)stateReducer router:(id<PresenterRouter>)router loggingProvider:(id<PresenterLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(presenter:stateLogger:stateReducer:router:loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (void)charPressedChar:(PresenterModelCharacter *)char_ __attribute__((swift_name("charPressed(char:)")));
- (void)setGameUidUid:(int32_t)uid __attribute__((swift_name("setGameUid(uid:)")));
- (void)viewResumed __attribute__((swift_name("viewResumed()")));
@end

__attribute__((swift_name("GamePresenter")))
@protocol PresenterGamePresenter <PresenterPresenter>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)showGameId:(int32_t)id completionHandler:(void (^)(PresenterArrow_coreEither<id<PresenterModelError>, PresenterKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("showGame(id:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GamePresenterImpl")))
@interface PresenterGamePresenterImpl : PresenterBase <PresenterGamePresenter>
- (instancetype)initWithCharacterProvider:(id<PresenterProvider>)characterProvider gameProvider:(id<PresenterProvider>)gameProvider imageProvider:(id<PresenterImageProvider>)imageProvider __attribute__((swift_name("init(characterProvider:gameProvider:imageProvider:)"))) __attribute__((objc_designated_initializer));
- (void)setViewView_:(id<PresenterGameView>)view __attribute__((swift_name("setView(view_:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)showGameId:(int32_t)id completionHandler:(void (^)(PresenterArrow_coreEither<id<PresenterModelError>, PresenterKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("showGame(id:completionHandler:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
@end

__attribute__((swift_name("GameView")))
@protocol PresenterGameView <PresenterView>
@required
- (void)displayUrl:(NSString *)url imgBase64:(NSString *)imgBase64 __attribute__((swift_name("display(url:imgBase64:)")));
- (void)displayCharacters:(NSArray<PresenterModelCharacter *> *)characters __attribute__((swift_name("display(characters:)")));
- (void)displayGame:(PresenterModelGame *)game __attribute__((swift_name("display(game:)")));
- (void)displayNotOnDiskUrl:(NSString *)url __attribute__((swift_name("displayNotOnDisk(url:)")));
@end

__attribute__((swift_name("HomeInteractor")))
@protocol PresenterHomeInteractor <PresenterInteractor>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)favPressedObj:(PresenterModelObj *)obj completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("favPressed(obj:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)gamePressedGame:(PresenterModelGame *)game completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("gamePressed(game:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HomeInteractorImpl")))
@interface PresenterHomeInteractorImpl : PresenterInteractorImpl<id<PresenterHomeView>, id<PresenterHomePresenter>> <PresenterHomeInteractor>
- (instancetype)initWithPresenter:(id<PresenterHomePresenter>)presenter stateLogger:(id<PresenterStateLogger>)stateLogger stateReducer:(id<PresenterStateReducer>)stateReducer loggingProvider:(id<PresenterLoggingProvider>)loggingProvider router:(id<PresenterRouter>)router context:(id<PresenterKotlinCoroutineContext>)context __attribute__((swift_name("init(presenter:stateLogger:stateReducer:loggingProvider:router:context:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPresenter:(id<PresenterPresenter>)presenter stateLogger:(id<PresenterStateLogger>)stateLogger stateReducer:(id<PresenterStateReducer>)stateReducer router:(id<PresenterRouter>)router loggingProvider:(id<PresenterLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(presenter:stateLogger:stateReducer:router:loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)favPressedObj:(PresenterModelObj *)obj completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("favPressed(obj:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)gamePressedGame:(PresenterModelGame *)game completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("gamePressed(game:completionHandler:)")));
- (void)viewResumed __attribute__((swift_name("viewResumed()")));
@end

__attribute__((swift_name("HomePresenter")))
@protocol PresenterHomePresenter <PresenterPresenter>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)showFavsWithCompletionHandler:(void (^)(PresenterArrow_coreEither<PresenterModelProviderError *, PresenterKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("showFavs(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)showGamesWithCompletionHandler:(void (^)(PresenterArrow_coreEither<PresenterModelProviderError *, PresenterKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("showGames(completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HomePresenterImpl")))
@interface PresenterHomePresenterImpl : PresenterPresenterImpl<id<PresenterHomeView>> <PresenterHomePresenter>
- (instancetype)initWithGameProvider:(id<PresenterProvider>)gameProvider imageProvider:(id<PresenterImageProvider>)imageProvider favoritesProvider:(id<PresenterFavoritesProvider>)favoritesProvider loggingProvider:(id<PresenterLoggingProvider>)loggingProvider __attribute__((swift_name("init(gameProvider:imageProvider:favoritesProvider:loggingProvider:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithView:(id<PresenterView> _Nullable)view loggingProvider:(id<PresenterLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(view:loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (void)setViewView_:(id<PresenterHomeView>)view __attribute__((swift_name("setView(view_:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)showFavsWithCompletionHandler:(void (^)(PresenterArrow_coreEither<PresenterModelProviderError *, PresenterKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("showFavs(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)showGamesWithCompletionHandler:(void (^)(PresenterArrow_coreEither<PresenterModelProviderError *, PresenterKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("showGames(completionHandler:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
@end

__attribute__((swift_name("HomeView")))
@protocol PresenterHomeView <PresenterView>
@required
- (void)displayUrl:(NSString *)url imgBase64:(NSString *)imgBase64 __attribute__((swift_name("display(url:imgBase64:)")));
- (void)displayFavsFavorites:(NSArray<PresenterModelObj *> *)favorites __attribute__((swift_name("displayFavs(favorites:)")));
- (void)displayFavsErrorError:(id<PresenterModelError>)error __attribute__((swift_name("displayFavsError(error:)")));
- (void)displayGamesGames:(NSArray<PresenterModelGame *> *)games __attribute__((swift_name("displayGames(games:)")));
- (void)displayGamesErrorError:(id<PresenterModelError>)error __attribute__((swift_name("displayGamesError(error:)")));
@end

__attribute__((swift_name("MovePresenter")))
@protocol PresenterMovePresenter <PresenterPresenter>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MovePresenterImpl")))
@interface PresenterMovePresenterImpl : PresenterBase <PresenterMovePresenter>
- (instancetype)initWithMoveProvider:(id<PresenterProvider>)moveProvider charProvider:(id<PresenterProvider>)charProvider gameProvider:(id<PresenterProvider>)gameProvider imageProvider:(id<PresenterImageProvider>)imageProvider __attribute__((swift_name("init(moveProvider:charProvider:gameProvider:imageProvider:)"))) __attribute__((objc_designated_initializer));
- (void)setViewView_:(id<PresenterMoveView>)view __attribute__((swift_name("setView(view_:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
@end

__attribute__((swift_name("MoveView")))
@protocol PresenterMoveView <PresenterView>
@required
@end

__attribute__((swift_name("RootPresenter")))
@protocol PresenterRootPresenter <PresenterPresenter>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RootPresenterImpl")))
@interface PresenterRootPresenterImpl : PresenterPresenterImpl<id<PresenterRootView>> <PresenterRootPresenter>
- (instancetype)initWithGameProvider:(id<PresenterProvider>)gameProvider loggingProvider:(id<PresenterLoggingProvider>)loggingProvider __attribute__((swift_name("init(gameProvider:loggingProvider:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithView:(id<PresenterView> _Nullable)view loggingProvider:(id<PresenterLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(view:loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (void)setViewView_:(id<PresenterRootView>)view __attribute__((swift_name("setView(view_:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
@end

__attribute__((swift_name("RootView")))
@protocol PresenterRootView <PresenterView>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ArrowExtensionsKt")))
@interface PresenterArrowExtensionsKt : PresenterBase
+ (PresenterArrow_coreEither<id, id> *)buildEitherLeftLeft:(id _Nullable)left __attribute__((swift_name("buildEitherLeft(left:)")));
+ (PresenterArrow_coreEither<id, id> *)buildEitherRightRight:(id _Nullable)right __attribute__((swift_name("buildEitherRight(right:)")));
+ (PresenterArrow_coreIor<id, id> *)buildIorBothLeft:(id _Nullable)left right:(id _Nullable)right __attribute__((swift_name("buildIorBoth(left:right:)")));
+ (PresenterArrow_coreIor<id, id> *)buildIorLeftLeft:(id _Nullable)left __attribute__((swift_name("buildIorLeft(left:)")));
+ (PresenterArrow_coreIor<id, id> *)buildIorRightRight:(id _Nullable)right __attribute__((swift_name("buildIorRight(right:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UtilsKt")))
@interface PresenterUtilsKt : PresenterBase
+ (int64_t)millisNow __attribute__((swift_name("millisNow()")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinCoroutineContext")))
@protocol PresenterKotlinCoroutineContext
@required
- (id _Nullable)foldInitial:(id _Nullable)initial operation:(id _Nullable (^)(id _Nullable, id<PresenterKotlinCoroutineContextElement>))operation __attribute__((swift_name("fold(initial:operation:)")));
- (id<PresenterKotlinCoroutineContextElement> _Nullable)getKey:(id<PresenterKotlinCoroutineContextKey>)key __attribute__((swift_name("get(key:)")));
- (id<PresenterKotlinCoroutineContext>)minusKeyKey:(id<PresenterKotlinCoroutineContextKey>)key __attribute__((swift_name("minusKey(key:)")));
- (id<PresenterKotlinCoroutineContext>)plusContext:(id<PresenterKotlinCoroutineContext>)context __attribute__((swift_name("plus(context:)")));
@end

__attribute__((swift_name("KotlinCoroutineContextElement")))
@protocol PresenterKotlinCoroutineContextElement <PresenterKotlinCoroutineContext>
@required
@property (readonly) id<PresenterKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinAbstractCoroutineContextElement")))
@interface PresenterKotlinAbstractCoroutineContextElement : PresenterBase <PresenterKotlinCoroutineContextElement>
- (instancetype)initWithKey:(id<PresenterKotlinCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer));
@property (readonly) id<PresenterKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinContinuationInterceptor")))
@protocol PresenterKotlinContinuationInterceptor <PresenterKotlinCoroutineContextElement>
@required
- (id<PresenterKotlinContinuation>)interceptContinuationContinuation:(id<PresenterKotlinContinuation>)continuation __attribute__((swift_name("interceptContinuation(continuation:)")));
- (void)releaseInterceptedContinuationContinuation:(id<PresenterKotlinContinuation>)continuation __attribute__((swift_name("releaseInterceptedContinuation(continuation:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineDispatcher")))
@interface PresenterKotlinx_coroutines_coreCoroutineDispatcher : PresenterKotlinAbstractCoroutineContextElement <PresenterKotlinContinuationInterceptor>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithKey:(id<PresenterKotlinCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) PresenterKotlinx_coroutines_coreCoroutineDispatcherKey *companion __attribute__((swift_name("companion")));
- (void)dispatchContext:(id<PresenterKotlinCoroutineContext>)context block:(id<PresenterKotlinx_coroutines_coreRunnable>)block __attribute__((swift_name("dispatch(context:block:)")));
- (void)dispatchYieldContext:(id<PresenterKotlinCoroutineContext>)context block:(id<PresenterKotlinx_coroutines_coreRunnable>)block __attribute__((swift_name("dispatchYield(context:block:)")));
- (id<PresenterKotlinContinuation>)interceptContinuationContinuation:(id<PresenterKotlinContinuation>)continuation __attribute__((swift_name("interceptContinuation(continuation:)")));
- (BOOL)isDispatchNeededContext:(id<PresenterKotlinCoroutineContext>)context __attribute__((swift_name("isDispatchNeeded(context:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (PresenterKotlinx_coroutines_coreCoroutineDispatcher *)limitedParallelismParallelism:(int32_t)parallelism __attribute__((swift_name("limitedParallelism(parallelism:)")));
- (PresenterKotlinx_coroutines_coreCoroutineDispatcher *)plusOther:(PresenterKotlinx_coroutines_coreCoroutineDispatcher *)other __attribute__((swift_name("plus(other:)"))) __attribute__((unavailable("Operator '+' on two CoroutineDispatcher objects is meaningless. CoroutineDispatcher is a coroutine context element and `+` is a set-sum operator for coroutine contexts. The dispatcher to the right of `+` just replaces the dispatcher to the left.")));
- (void)releaseInterceptedContinuationContinuation:(id<PresenterKotlinContinuation>)continuation __attribute__((swift_name("releaseInterceptedContinuation(continuation:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("KotlinComparable")))
@protocol PresenterKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end

__attribute__((swift_name("KotlinEnum")))
@interface PresenterKotlinEnum<E> : PresenterBase <PresenterKotlinComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PresenterKotlinEnumCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelEvent.ViewTag")))
@interface PresenterModelEventViewTag : PresenterKotlinEnum<PresenterModelEventViewTag *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) PresenterModelEventViewTag *homeView __attribute__((swift_name("homeView")));
@property (class, readonly) PresenterModelEventViewTag *gameView __attribute__((swift_name("gameView")));
@property (class, readonly) PresenterModelEventViewTag *charView __attribute__((swift_name("charView")));
+ (PresenterKotlinArray<PresenterModelEventViewTag *> *)values __attribute__((swift_name("values()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelEvent")))
@interface PresenterModelEvent : PresenterBase
- (instancetype)initWithView:(PresenterModelEventViewTag *)view value:(PresenterModelEventValue *)value extras:(NSDictionary<NSString *, id> *)extras __attribute__((swift_name("init(view:value:extras:)"))) __attribute__((objc_designated_initializer));
- (PresenterModelEvent *)doCopyView:(PresenterModelEventViewTag *)view value:(PresenterModelEventValue *)value extras:(NSDictionary<NSString *, id> *)extras __attribute__((swift_name("doCopy(view:value:extras:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSDictionary<NSString *, id> *extras __attribute__((swift_name("extras")));
@property (readonly) PresenterModelEventValue *value __attribute__((swift_name("value")));
@property (readonly) PresenterModelEventViewTag *view __attribute__((swift_name("view")));
@end

__attribute__((swift_name("ModelError")))
@protocol PresenterModelError
@required
@end

__attribute__((swift_name("ModelProviderError")))
@interface PresenterModelProviderError : PresenterBase <PresenterModelError>
@end

__attribute__((swift_name("Arrow_coreEither")))
@interface PresenterArrow_coreEither<__covariant A, __covariant B> : PresenterBase
@property (class, readonly, getter=companion) PresenterArrow_coreEitherCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)allPredicate:(PresenterBoolean *(^)(B _Nullable))predicate __attribute__((swift_name("all(predicate:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (id _Nullable)bifoldLeftC:(id _Nullable)c f:(id _Nullable (^)(id _Nullable, A _Nullable))f g:(id _Nullable (^)(id _Nullable, B _Nullable))g __attribute__((swift_name("bifoldLeft(c:f:g:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (id _Nullable)bifoldMapMN:(id<PresenterArrow_coreMonoid>)MN f:(id _Nullable (^)(A _Nullable))f g:(id _Nullable (^)(B _Nullable))g __attribute__((swift_name("bifoldMap(MN:f:g:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (PresenterArrow_coreEither<id, id> *)bimapLeftOperation:(id _Nullable (^)(A _Nullable))leftOperation rightOperation:(id _Nullable (^)(B _Nullable))rightOperation __attribute__((swift_name("bimap(leftOperation:rightOperation:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Either DSL, or map + mapLeft")));
- (NSArray<PresenterArrow_coreEither<id, id> *> *)bitraverseFe:(id (^)(A _Nullable))fe fa:(id (^)(B _Nullable))fa __attribute__((swift_name("bitraverse(fe:fa:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicit fold instead")));
- (PresenterArrow_coreEither<id, id> * _Nullable)bitraverseNullableFl:(id _Nullable (^)(A _Nullable))fl fr:(id _Nullable (^)(B _Nullable))fr __attribute__((swift_name("bitraverseNullable(fl:fr:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicit fold instead")));
- (PresenterArrow_coreOption<PresenterArrow_coreEither<id, id> *> *)bitraverseOptionFl:(PresenterArrow_coreOption<id> *(^)(A _Nullable))fl fr:(PresenterArrow_coreOption<id> *(^)(B _Nullable))fr __attribute__((swift_name("bitraverseOption(fl:fr:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicit fold instead")));
- (PresenterArrow_coreValidated<id, PresenterArrow_coreEither<id, id> *> *)bitraverseValidatedFe:(PresenterArrow_coreValidated<id, id> *(^)(A _Nullable))fe fa:(PresenterArrow_coreValidated<id, id> *(^)(B _Nullable))fa __attribute__((swift_name("bitraverseValidated(fe:fa:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicit fold instead")));
- (BOOL)existPredicate:(PresenterBoolean *(^)(B _Nullable))predicate __attribute__((swift_name("exist(predicate:)"))) __attribute__((deprecated("Facilitates the migration from Validated to Either.")));
- (BOOL)existsPredicate:(PresenterBoolean *(^)(B _Nullable))predicate __attribute__((swift_name("exists(predicate:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer isRight")));
- (B _Nullable)findOrNullPredicate:(PresenterBoolean *(^)(B _Nullable))predicate __attribute__((swift_name("findOrNull(predicate:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer Kotlin nullable syntax instead")));
- (id _Nullable)foldIfLeft:(id _Nullable (^)(A _Nullable))ifLeft ifRight:(id _Nullable (^)(B _Nullable))ifRight __attribute__((swift_name("fold(ifLeft:ifRight:)")));
- (id _Nullable)foldLeftInitial:(id _Nullable)initial rightOperation:(id _Nullable (^)(id _Nullable, B _Nullable))rightOperation __attribute__((swift_name("foldLeft(initial:rightOperation:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (id _Nullable)foldMapMN:(id<PresenterArrow_coreMonoid>)MN f:(id _Nullable (^)(B _Nullable))f __attribute__((swift_name("foldMap(MN:f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (PresenterArrow_coreOption<B> *)getOrNone __attribute__((swift_name("getOrNone()")));
- (B _Nullable)getOrNull __attribute__((swift_name("getOrNull()")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse isLeft()")));
- (BOOL)isLeft __attribute__((swift_name("isLeft()")));
- (BOOL)isLeftPredicate:(PresenterBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("isLeft(predicate:)")));
- (BOOL)isNotEmpty __attribute__((swift_name("isNotEmpty()"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse isRight()")));
- (BOOL)isRight __attribute__((swift_name("isRight()")));
- (BOOL)isRightPredicate:(PresenterBoolean *(^)(B _Nullable))predicate __attribute__((swift_name("isRight(predicate:)")));
- (A _Nullable)leftOrNull __attribute__((swift_name("leftOrNull()")));
- (PresenterArrow_coreEither<A, id> *)mapF:(id _Nullable (^)(B _Nullable))f __attribute__((swift_name("map(f:)")));
- (PresenterArrow_coreEither<id, B> *)mapLeftF:(id _Nullable (^)(A _Nullable))f __attribute__((swift_name("mapLeft(f:)")));
- (PresenterArrow_coreEither<A, B> *)onLeftAction:(void (^)(A _Nullable))action __attribute__((swift_name("onLeft(action:)")));
- (PresenterArrow_coreEither<A, B> *)onRightAction:(void (^)(B _Nullable))action __attribute__((swift_name("onRight(action:)")));
- (PresenterArrow_coreOption<B> *)orNone __attribute__((swift_name("orNone()"))) __attribute__((deprecated("orNone is being renamed to getOrNone to be more consistent with the Kotlin Standard Library naming")));
- (B _Nullable)orNull __attribute__((swift_name("orNull()"))) __attribute__((deprecated("orNull is being renamed to getOrNull to be more consistent with the Kotlin Standard Library naming")));
- (PresenterArrow_coreEither<A, NSArray<id> *> *)replicateN:(int32_t)n __attribute__((swift_name("replicate(n:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Either DSL, or map")));
- (PresenterArrow_coreEither<B, A> *)swap __attribute__((swift_name("swap()")));
- (PresenterArrow_coreEither<A, B> *)tapF:(void (^)(B _Nullable))f __attribute__((swift_name("tap(f:)"))) __attribute__((deprecated("tap is being renamed to onRight to be more consistent with the Kotlin Standard Library naming")));
- (PresenterArrow_coreEither<A, B> *)tapLeftF:(void (^)(A _Nullable))f __attribute__((swift_name("tapLeft(f:)"))) __attribute__((deprecated("tapLeft is being renamed to onLeft to be more consistent with the Kotlin Standard Library naming")));
- (PresenterArrow_coreEither<A, B> *)toEither __attribute__((swift_name("toEither()"))) __attribute__((deprecated("Facilitates the migration from Validated to Either, you can simply remove this method call.")));
- (PresenterArrow_coreIor<A, B> *)toIor __attribute__((swift_name("toIor()")));
- (NSString *)description __attribute__((swift_name("description()")));
- (PresenterArrow_coreValidated<A, B> *)toValidated __attribute__((swift_name("toValidated()"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nYou can find more details about how to migrate on the Github release page, or the 1.2.0 release post.")));
- (PresenterArrow_coreValidated<NSArray<id> *, B> *)toValidatedNel __attribute__((swift_name("toValidatedNel()"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nValidatedNel is being replaced by EitherNel")));
- (PresenterArrow_coreOption<PresenterArrow_coreEither<A, id> *> *)traverseFa:(PresenterArrow_coreOption<id> *(^)(B _Nullable))fa __attribute__((swift_name("traverse(fa:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Either DSL, or explicit fold or when")));
- (PresenterArrow_coreValidated<id, PresenterArrow_coreEither<A, id> *> *)traverseFa_:(PresenterArrow_coreValidated<id, id> *(^)(B _Nullable))fa __attribute__((swift_name("traverse(fa_:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Either DSL, or explicit fold or when")));
- (NSArray<PresenterArrow_coreEither<A, id> *> *)traverseFa__:(id (^)(B _Nullable))fa __attribute__((swift_name("traverse(fa__:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Either DSL, or explicit fold or when")));
- (PresenterArrow_coreEither<A, id> * _Nullable)traverseNullableFa:(id _Nullable (^)(B _Nullable))fa __attribute__((swift_name("traverseNullable(fa:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse orNull() and Kotlin nullable types")));
- (PresenterArrow_coreOption<PresenterArrow_coreEither<A, id> *> *)traverseOptionFa:(PresenterArrow_coreOption<id> *(^)(B _Nullable))fa __attribute__((swift_name("traverseOption(fa:)"))) __attribute__((deprecated("traverseOption is being renamed to traverse to simplify the Arrow API")));
- (PresenterArrow_coreValidated<id, PresenterArrow_coreEither<A, id> *> *)traverseValidatedFa:(PresenterArrow_coreValidated<id, id> *(^)(B _Nullable))fa __attribute__((swift_name("traverseValidated(fa:)"))) __attribute__((deprecated("traverseValidated is being renamed to traverse to simplify the Arrow API")));
- (PresenterArrow_coreEither<A, PresenterKotlinUnit *> *)void __attribute__((swift_name("void()"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nMap with Unit")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinUnit")))
@interface PresenterKotlinUnit : PresenterBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)unit __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PresenterKotlinUnit *shared __attribute__((swift_name("shared")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("ModelObj")))
@interface PresenterModelObj : PresenterBase
- (instancetype)initWithUid:(int32_t)uid __attribute__((swift_name("init(uid:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t uid __attribute__((swift_name("uid")));
@end

__attribute__((swift_name("Arrow_coreIor")))
@interface PresenterArrow_coreIor<__covariant A, __covariant B> : PresenterBase
@property (class, readonly, getter=companion) PresenterArrow_coreIorCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)allPredicate:(PresenterBoolean *(^)(B _Nullable))predicate __attribute__((swift_name("all(predicate:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using fold, or map + getOrElse. See the Arrow web migration guide for more info.")));
- (NSArray<PresenterArrow_coreIor<id, id> *> *)bicrosswalkFa:(id (^)(A _Nullable))fa fb:(id (^)(B _Nullable))fb __attribute__((swift_name("bicrosswalk(fa:fb:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (NSDictionary<id, PresenterArrow_coreIor<id, id> *> *)bicrosswalkMapFa:(NSDictionary<id, id> *(^)(A _Nullable))fa fb:(NSDictionary<id, id> *(^)(B _Nullable))fb __attribute__((swift_name("bicrosswalkMap(fa:fb:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterArrow_coreIor<id, id> * _Nullable)bicrosswalkNullFa:(id _Nullable (^)(A _Nullable))fa fb:(id _Nullable (^)(B _Nullable))fb __attribute__((swift_name("bicrosswalkNull(fa:fb:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (id _Nullable)bifoldLeftC:(id _Nullable)c f:(id _Nullable (^)(id _Nullable, A _Nullable))f g:(id _Nullable (^)(id _Nullable, B _Nullable))g __attribute__((swift_name("bifoldLeft(c:f:g:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (id _Nullable)bifoldMapMN:(id<PresenterArrow_coreMonoid>)MN f:(id _Nullable (^)(A _Nullable))f g:(id _Nullable (^)(B _Nullable))g __attribute__((swift_name("bifoldMap(MN:f:g:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead. See the Arrow web migration guide for more info.")));
- (PresenterArrow_coreIor<id, id> *)bimapFa:(id _Nullable (^)(A _Nullable))fa fb:(id _Nullable (^)(B _Nullable))fb __attribute__((swift_name("bimap(fa:fb:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Either DSL, or map + mapLeft")));
- (NSArray<PresenterArrow_coreIor<id, id> *> *)bitraverseFa:(id (^)(A _Nullable))fa fb:(id (^)(B _Nullable))fb __attribute__((swift_name("bitraverse(fa:fb:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterArrow_coreEither<id, PresenterArrow_coreIor<id, id> *> *)bitraverseEitherFa:(PresenterArrow_coreEither<id, id> *(^)(A _Nullable))fa fb:(PresenterArrow_coreEither<id, id> *(^)(B _Nullable))fb __attribute__((swift_name("bitraverseEither(fa:fb:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterArrow_coreIor<id, id> * _Nullable)bitraverseNullableFa:(id _Nullable (^)(A _Nullable))fa fb:(id _Nullable (^)(B _Nullable))fb __attribute__((swift_name("bitraverseNullable(fa:fb:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterArrow_coreOption<PresenterArrow_coreIor<id, id> *> *)bitraverseOptionFa:(PresenterArrow_coreOption<id> *(^)(A _Nullable))fa fb:(PresenterArrow_coreOption<id> *(^)(B _Nullable))fb __attribute__((swift_name("bitraverseOption(fa:fb:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterArrow_coreValidated<id, PresenterArrow_coreIor<id, id> *> *)bitraverseValidatedSA:(id<PresenterArrow_coreSemigroup>)SA fa:(PresenterArrow_coreValidated<id, id> *(^)(A _Nullable))fa fb:(PresenterArrow_coreValidated<id, id> *(^)(B _Nullable))fb __attribute__((swift_name("bitraverseValidated(SA:fa:fb:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (NSArray<PresenterArrow_coreIor<A, id> *> *)crosswalkFa:(id (^)(B _Nullable))fa __attribute__((swift_name("crosswalk(fa:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (NSDictionary<id, PresenterArrow_coreIor<A, id> *> *)crosswalkMapFa:(NSDictionary<id, id> *(^)(B _Nullable))fa __attribute__((swift_name("crosswalkMap(fa:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterArrow_coreIor<id, id> * _Nullable)crosswalkNullIor:(PresenterArrow_coreIor<id, id> *)ior fa:(id _Nullable (^)(id _Nullable))fa __attribute__((swift_name("crosswalkNull(ior:fa:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (BOOL)existsPredicate:(PresenterBoolean *(^)(B _Nullable))predicate __attribute__((swift_name("exists(predicate:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using fold, or map + getOrElse")));
- (B _Nullable)findOrNullPredicate:(PresenterBoolean *(^)(B _Nullable))predicate __attribute__((swift_name("findOrNull(predicate:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer Kotlin nullable syntax instead")));
- (id _Nullable)foldFa:(id _Nullable (^)(A _Nullable))fa fb:(id _Nullable (^)(B _Nullable))fb fab:(id _Nullable (^)(A _Nullable, B _Nullable))fab __attribute__((swift_name("fold(fa:fb:fab:)")));
- (id _Nullable)foldLeftC:(id _Nullable)c f:(id _Nullable (^)(id _Nullable, B _Nullable))f __attribute__((swift_name("foldLeft(c:f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (id _Nullable)foldMapMN:(id<PresenterArrow_coreMonoid>)MN f:(id _Nullable (^)(B _Nullable))f __attribute__((swift_name("foldMap(MN:f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (B _Nullable)getOrNull __attribute__((swift_name("getOrNull()")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="_isBoth")
*/
- (BOOL)isBoth __attribute__((swift_name("isBoth()")));
- (BOOL)isBothLeftPredicate:(PresenterBoolean *(^)(A _Nullable))leftPredicate rightPredicate:(PresenterBoolean *(^)(B _Nullable))rightPredicate __attribute__((swift_name("isBoth(leftPredicate:rightPredicate:)")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using isLeft")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="_isLeft")
*/
- (BOOL)isLeft __attribute__((swift_name("isLeft()")));
- (BOOL)isLeftPredicate:(PresenterBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("isLeft(predicate:)")));
- (BOOL)isNotEmpty __attribute__((swift_name("isNotEmpty()"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using isRight and isBoth")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="_isRight")
*/
- (BOOL)isRight __attribute__((swift_name("isRight()")));
- (BOOL)isRightPredicate:(PresenterBoolean *(^)(B _Nullable))predicate __attribute__((swift_name("isRight(predicate:)")));
- (A _Nullable)leftOrNull __attribute__((swift_name("leftOrNull()")));
- (PresenterArrow_coreIor<A, id> *)mapF:(id _Nullable (^)(B _Nullable))f __attribute__((swift_name("map(f:)")));
- (PresenterArrow_coreIor<id, B> *)mapLeftFa:(id _Nullable (^)(A _Nullable))fa __attribute__((swift_name("mapLeft(fa:)")));
- (B _Nullable)orNull __attribute__((swift_name("orNull()"))) __attribute__((deprecated("orNull is being renamed to getOrNull to be more consistent with the Kotlin Standard Library naming")));
- (PresenterKotlinPair<A, B> *)padNull __attribute__((swift_name("padNull()"))) __attribute__((deprecated("padNull is being renamed to toPair to be more consistent with the Kotlin Standard Library naming")));
- (PresenterArrow_coreIor<B, A> *)swap __attribute__((swift_name("swap()")));
- (PresenterArrow_coreEither<A, B> *)toEither __attribute__((swift_name("toEither()")));
- (PresenterKotlinPair<A, B> *)toPair __attribute__((swift_name("toPair()")));
- (NSString *)description __attribute__((swift_name("description()")));
- (PresenterArrow_coreValidated<A, B> *)toValidated __attribute__((swift_name("toValidated()"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using fold. See the Arrow web migration guide for more info.")));
- (PresenterArrow_coreEither<id, PresenterArrow_coreIor<A, id> *> *)traverseFa:(PresenterArrow_coreEither<id, id> *(^)(B _Nullable))fa __attribute__((swift_name("traverse(fa:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterArrow_coreOption<PresenterArrow_coreIor<A, id> *> *)traverseFa_:(PresenterArrow_coreOption<id> *(^)(B _Nullable))fa __attribute__((swift_name("traverse(fa_:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterArrow_coreValidated<id, PresenterArrow_coreIor<A, id> *> *)traverseFa__:(PresenterArrow_coreValidated<id, id> *(^)(B _Nullable))fa __attribute__((swift_name("traverse(fa__:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when")));
- (NSArray<PresenterArrow_coreIor<A, id> *> *)traverseFa___:(id (^)(B _Nullable))fa __attribute__((swift_name("traverse(fa___:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterArrow_coreEither<id, PresenterArrow_coreIor<A, id> *> *)traverseEitherFa:(PresenterArrow_coreEither<id, id> *(^)(B _Nullable))fa __attribute__((swift_name("traverseEither(fa:)"))) __attribute__((deprecated("traverseEither is being renamed to traverse to simplify the Arrow API")));
- (PresenterArrow_coreIor<A, id> * _Nullable)traverseNullableFa:(id _Nullable (^)(B _Nullable))fa __attribute__((swift_name("traverseNullable(fa:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterArrow_coreOption<PresenterArrow_coreIor<A, id> *> *)traverseOptionFa:(PresenterArrow_coreOption<id> *(^)(B _Nullable))fa __attribute__((swift_name("traverseOption(fa:)"))) __attribute__((deprecated("traverseOption is being renamed to traverse to simplify the Arrow API")));
- (PresenterArrow_coreValidated<id, PresenterArrow_coreIor<A, id> *> *)traverseValidatedFa:(PresenterArrow_coreValidated<id, id> *(^)(B _Nullable))fa __attribute__((swift_name("traverseValidated(fa:)"))) __attribute__((deprecated("traverseValidated is being renamed to traverse to simplify the Arrow API")));
- (PresenterArrow_coreEither<PresenterArrow_coreEither<A, B> *, PresenterKotlinPair<A, B> *> *)unwrap __attribute__((swift_name("unwrap()")));
- (PresenterArrow_coreIor<A, PresenterKotlinUnit *> *)void __attribute__((swift_name("void()"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using map")));
@property (readonly, getter=isBoth_) BOOL isBoth __attribute__((swift_name("isBoth"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse isBoth()")));
@property (readonly, getter=isLeft_) BOOL isLeft __attribute__((swift_name("isLeft"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse isLeft()")));
@property (readonly, getter=isRight_) BOOL isRight __attribute__((swift_name("isRight"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse isRight()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelLevel")))
@interface PresenterModelLevel : PresenterKotlinEnum<PresenterModelLevel *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) PresenterModelLevel *debug __attribute__((swift_name("debug")));
@property (class, readonly) PresenterModelLevel *alert __attribute__((swift_name("alert")));
+ (PresenterKotlinArray<PresenterModelLevel *> *)values __attribute__((swift_name("values()")));
@end

__attribute__((swift_name("KotlinThrowable")))
@interface PresenterKotlinThrowable : PresenterBase
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(PresenterKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(PresenterKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.experimental.ExperimentalNativeApi
*/
- (PresenterKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) PresenterKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
- (NSError *)asError __attribute__((swift_name("asError()")));
@end

__attribute__((swift_name("KotlinException")))
@interface PresenterKotlinException : PresenterKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(PresenterKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(PresenterKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinRuntimeException")))
@interface PresenterKotlinRuntimeException : PresenterKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(PresenterKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(PresenterKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinIllegalStateException")))
@interface PresenterKotlinIllegalStateException : PresenterKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(PresenterKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(PresenterKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
__attribute__((swift_name("KotlinCancellationException")))
@interface PresenterKotlinCancellationException : PresenterKotlinIllegalStateException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(PresenterKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(PresenterKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelIncorrectCount")))
@interface PresenterModelIncorrectCount : PresenterModelProviderError
- (instancetype)initWithIds:(NSArray<PresenterInt *> *)ids __attribute__((swift_name("init(ids:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSArray<PresenterInt *> *ids __attribute__((swift_name("ids")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelMove")))
@interface PresenterModelMove : PresenterModelObj
- (instancetype)initWithUid:(int32_t)uid name:(NSString *)name attributes:(NSDictionary<NSString *, NSString *> *)attributes __attribute__((swift_name("init(uid:name:attributes:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithUid:(int32_t)uid __attribute__((swift_name("init(uid:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (PresenterModelMove *)doCopyUid:(int32_t)uid name:(NSString *)name attributes:(NSDictionary<NSString *, NSString *> *)attributes __attribute__((swift_name("doCopy(uid:name:attributes:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSDictionary<NSString *, NSString *> *attributes __attribute__((swift_name("attributes")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t uid __attribute__((swift_name("uid")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelCharacter")))
@interface PresenterModelCharacter : PresenterModelObj
- (instancetype)initWithUid:(int32_t)uid name:(NSString *)name attributes:(NSDictionary<NSString *, NSString *> *)attributes moveIds:(NSArray<PresenterInt *> *)moveIds iconUrl:(NSString *)iconUrl __attribute__((swift_name("init(uid:name:attributes:moveIds:iconUrl:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithUid:(int32_t)uid __attribute__((swift_name("init(uid:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (PresenterModelCharacter *)doCopyUid:(int32_t)uid name:(NSString *)name attributes:(NSDictionary<NSString *, NSString *> *)attributes moveIds:(NSArray<PresenterInt *> *)moveIds iconUrl:(NSString *)iconUrl __attribute__((swift_name("doCopy(uid:name:attributes:moveIds:iconUrl:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSDictionary<NSString *, NSString *> *attributes __attribute__((swift_name("attributes")));
@property (readonly) NSString *iconUrl __attribute__((swift_name("iconUrl")));
@property (readonly) NSArray<PresenterInt *> *moveIds __attribute__((swift_name("moveIds")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t uid __attribute__((swift_name("uid")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelGame")))
@interface PresenterModelGame : PresenterModelObj
- (instancetype)initWithUid:(int32_t)uid name:(NSString *)name charIds:(NSArray<PresenterInt *> *)charIds iconUrl:(NSString *)iconUrl __attribute__((swift_name("init(uid:name:charIds:iconUrl:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithUid:(int32_t)uid __attribute__((swift_name("init(uid:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (PresenterModelGame *)doCopyUid:(int32_t)uid name:(NSString *)name charIds:(NSArray<PresenterInt *> *)charIds iconUrl:(NSString *)iconUrl __attribute__((swift_name("doCopy(uid:name:charIds:iconUrl:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<PresenterInt *> *charIds __attribute__((swift_name("charIds")));
@property (readonly) NSString *iconUrl __attribute__((swift_name("iconUrl")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t uid __attribute__((swift_name("uid")));
@end

__attribute__((swift_name("KotlinCoroutineContextKey")))
@protocol PresenterKotlinCoroutineContextKey
@required
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinContinuation")))
@protocol PresenterKotlinContinuation
@required
- (void)resumeWithResult:(id _Nullable)result __attribute__((swift_name("resumeWith(result:)")));
@property (readonly) id<PresenterKotlinCoroutineContext> context __attribute__((swift_name("context")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
 *   kotlin.ExperimentalStdlibApi
*/
__attribute__((swift_name("KotlinAbstractCoroutineContextKey")))
@interface PresenterKotlinAbstractCoroutineContextKey<B, E> : PresenterBase <PresenterKotlinCoroutineContextKey>
- (instancetype)initWithBaseKey:(id<PresenterKotlinCoroutineContextKey>)baseKey safeCast:(E _Nullable (^)(id<PresenterKotlinCoroutineContextElement>))safeCast __attribute__((swift_name("init(baseKey:safeCast:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.ExperimentalStdlibApi
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineDispatcher.Key")))
@interface PresenterKotlinx_coroutines_coreCoroutineDispatcherKey : PresenterKotlinAbstractCoroutineContextKey<id<PresenterKotlinContinuationInterceptor>, PresenterKotlinx_coroutines_coreCoroutineDispatcher *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithBaseKey:(id<PresenterKotlinCoroutineContextKey>)baseKey safeCast:(id<PresenterKotlinCoroutineContextElement> _Nullable (^)(id<PresenterKotlinCoroutineContextElement>))safeCast __attribute__((swift_name("init(baseKey:safeCast:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)key __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PresenterKotlinx_coroutines_coreCoroutineDispatcherKey *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreRunnable")))
@protocol PresenterKotlinx_coroutines_coreRunnable
@required
- (void)run __attribute__((swift_name("run()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinEnumCompanion")))
@interface PresenterKotlinEnumCompanion : PresenterBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PresenterKotlinEnumCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface PresenterKotlinArray<T> : PresenterBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(PresenterInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<PresenterKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelEvent.Value")))
@interface PresenterModelEventValue : PresenterKotlinEnum<PresenterModelEventValue *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) PresenterModelEventValue *viewEntered __attribute__((swift_name("viewEntered")));
@property (class, readonly) PresenterModelEventValue *viewExited __attribute__((swift_name("viewExited")));
@property (class, readonly) PresenterModelEventValue *buttonPressed __attribute__((swift_name("buttonPressed")));
@property (class, readonly) PresenterModelEventValue *routingRequest __attribute__((swift_name("routingRequest")));
@property (class, readonly) PresenterModelEventValue *routingDenied __attribute__((swift_name("routingDenied")));
+ (PresenterKotlinArray<PresenterModelEventValue *> *)values __attribute__((swift_name("values()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Arrow_coreEitherCompanion")))
@interface PresenterArrow_coreEitherCompanion : PresenterBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PresenterArrow_coreEitherCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
 *   kotlin.jvm.JvmName(name="tryCatch")
*/
- (PresenterArrow_coreEither<PresenterKotlinThrowable *, id> *)catchF:(id _Nullable (^)(void))f __attribute__((swift_name("catch(f:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
 *   kotlin.jvm.JvmName(name="tryCatch")
*/
- (PresenterArrow_coreEither<id, id> *)catchFe:(id _Nullable (^)(PresenterKotlinThrowable *))fe f:(id _Nullable (^)(void))f __attribute__((swift_name("catch(fe:f:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nCompose catch with mapLeft instead")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
 *   kotlin.jvm.JvmName(name="tryCatchAndFlatten")
*/
- (PresenterArrow_coreEither<PresenterKotlinThrowable *, id> *)catchAndFlattenF:(PresenterArrow_coreEither<PresenterKotlinThrowable *, id> *(^)(void))f __attribute__((swift_name("catchAndFlatten(f:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nCompose catch with flatten instead")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreEither<PresenterKotlinThrowable *, id> *)catchOrThrowF:(id _Nullable (^)(void))f __attribute__((swift_name("catchOrThrow(f:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreEither<id, id> *)conditionallyTest:(BOOL)test ifFalse:(id _Nullable (^)(void))ifFalse ifTrue:(id _Nullable (^)(void))ifTrue __attribute__((swift_name("conditionally(test:ifFalse:ifTrue:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicit if-else statements, or ensure inside Either DSL")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreEither<PresenterKotlinUnit *, id> *)fromNullableA:(id _Nullable)a __attribute__((swift_name("fromNullable(a:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer Kotlin nullable syntax, or ensureNotNull inside Either DSL")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreEither<id, id> *(^)(PresenterArrow_coreEither<id, id> *))liftFa:(id _Nullable (^)(id _Nullable))fa fb:(id _Nullable (^)(id _Nullable))fb __attribute__((swift_name("lift(fa:fb:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicitly creating lambdas")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreEither<id, id> *(^)(PresenterArrow_coreEither<id, id> *))liftF:(id _Nullable (^)(id _Nullable))f __attribute__((swift_name("lift(f:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicitly creating lambdas")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (id _Nullable)resolveF:(PresenterArrow_coreEither<id, id> *(^)(void))f success:(PresenterArrow_coreEither<PresenterKotlinThrowable *, id> *(^)(id _Nullable))success error:(PresenterArrow_coreEither<PresenterKotlinThrowable *, id> *(^)(id _Nullable))error throwable:(PresenterArrow_coreEither<PresenterKotlinThrowable *, id> *(^)(PresenterKotlinThrowable *))throwable unrecoverableState:(PresenterArrow_coreEither<PresenterKotlinThrowable *, PresenterKotlinUnit *> *(^)(PresenterKotlinThrowable *))unrecoverableState __attribute__((swift_name("resolve(f:success:error:throwable:unrecoverableState:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using recover, catch and the either DSL to work with errors")));
- (PresenterArrow_coreEither<id, id> *)zipOrAccumulateCombine:(id _Nullable (^)(id _Nullable, id _Nullable))combine a:(PresenterArrow_coreEither<id, id> *)a b:(PresenterArrow_coreEither<id, id> *)b transform:(id _Nullable (^)(id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(combine:a:b:transform:)")));
- (PresenterArrow_coreEither<id, id> *)zipOrAccumulateCombine:(id _Nullable (^)(id _Nullable, id _Nullable))combine a:(PresenterArrow_coreEither<id, id> *)a b:(PresenterArrow_coreEither<id, id> *)b c:(PresenterArrow_coreEither<id, id> *)c transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(combine:a:b:c:transform:)")));
- (PresenterArrow_coreEither<id, id> *)zipOrAccumulateCombine:(id _Nullable (^)(id _Nullable, id _Nullable))combine a:(PresenterArrow_coreEither<id, id> *)a b:(PresenterArrow_coreEither<id, id> *)b c:(PresenterArrow_coreEither<id, id> *)c d:(PresenterArrow_coreEither<id, id> *)d transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(combine:a:b:c:d:transform:)")));
- (PresenterArrow_coreEither<id, id> *)zipOrAccumulateCombine:(id _Nullable (^)(id _Nullable, id _Nullable))combine a:(PresenterArrow_coreEither<id, id> *)a b:(PresenterArrow_coreEither<id, id> *)b c:(PresenterArrow_coreEither<id, id> *)c d:(PresenterArrow_coreEither<id, id> *)d e:(PresenterArrow_coreEither<id, id> *)e transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(combine:a:b:c:d:e:transform:)")));
- (PresenterArrow_coreEither<id, id> *)zipOrAccumulateCombine:(id _Nullable (^)(id _Nullable, id _Nullable))combine a:(PresenterArrow_coreEither<id, id> *)a b:(PresenterArrow_coreEither<id, id> *)b c:(PresenterArrow_coreEither<id, id> *)c d:(PresenterArrow_coreEither<id, id> *)d e:(PresenterArrow_coreEither<id, id> *)e f:(PresenterArrow_coreEither<id, id> *)f g:(PresenterArrow_coreEither<id, id> *)g transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(combine:a:b:c:d:e:f:g:transform:)")));
- (PresenterArrow_coreEither<id, id> *)zipOrAccumulateCombine:(id _Nullable (^)(id _Nullable, id _Nullable))combine a:(PresenterArrow_coreEither<id, id> *)a b:(PresenterArrow_coreEither<id, id> *)b c:(PresenterArrow_coreEither<id, id> *)c d:(PresenterArrow_coreEither<id, id> *)d e:(PresenterArrow_coreEither<id, id> *)e f:(PresenterArrow_coreEither<id, id> *)f g:(PresenterArrow_coreEither<id, id> *)g h:(PresenterArrow_coreEither<id, id> *)h transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(combine:a:b:c:d:e:f:g:h:transform:)")));
- (PresenterArrow_coreEither<id, id> *)zipOrAccumulateCombine:(id _Nullable (^)(id _Nullable, id _Nullable))combine a:(PresenterArrow_coreEither<id, id> *)a b:(PresenterArrow_coreEither<id, id> *)b c:(PresenterArrow_coreEither<id, id> *)c d:(PresenterArrow_coreEither<id, id> *)d e:(PresenterArrow_coreEither<id, id> *)e f:(PresenterArrow_coreEither<id, id> *)f g:(PresenterArrow_coreEither<id, id> *)g h:(PresenterArrow_coreEither<id, id> *)h i:(PresenterArrow_coreEither<id, id> *)i transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(combine:a:b:c:d:e:f:g:h:i:transform:)")));
- (PresenterArrow_coreEither<id, id> *)zipOrAccumulateCombine:(id _Nullable (^)(id _Nullable, id _Nullable))combine a:(PresenterArrow_coreEither<id, id> *)a b:(PresenterArrow_coreEither<id, id> *)b c:(PresenterArrow_coreEither<id, id> *)c d:(PresenterArrow_coreEither<id, id> *)d e:(PresenterArrow_coreEither<id, id> *)e f:(PresenterArrow_coreEither<id, id> *)f g:(PresenterArrow_coreEither<id, id> *)g h:(PresenterArrow_coreEither<id, id> *)h i:(PresenterArrow_coreEither<id, id> *)i j:(PresenterArrow_coreEither<id, id> *)j transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(combine:a:b:c:d:e:f:g:h:i:j:transform:)")));
- (PresenterArrow_coreEither<id, id> *)zipOrAccumulateCombine:(id _Nullable (^)(id _Nullable, id _Nullable))combine a:(PresenterArrow_coreEither<id, id> *)a b:(PresenterArrow_coreEither<id, id> *)b c:(PresenterArrow_coreEither<id, id> *)c d:(PresenterArrow_coreEither<id, id> *)d e:(PresenterArrow_coreEither<id, id> *)e f:(PresenterArrow_coreEither<id, id> *)f transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(combine:a:b:c:d:e:f:transform:)")));
- (PresenterArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterArrow_coreEither<id, id> *)a b:(PresenterArrow_coreEither<id, id> *)b transform:(id _Nullable (^)(id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:transform:)")));
- (PresenterArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterArrow_coreEither<id, id> *)a b:(PresenterArrow_coreEither<id, id> *)b c:(PresenterArrow_coreEither<id, id> *)c transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:transform:)")));
- (PresenterArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterArrow_coreEither<id, id> *)a b:(PresenterArrow_coreEither<id, id> *)b c:(PresenterArrow_coreEither<id, id> *)c d:(PresenterArrow_coreEither<id, id> *)d transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:transform:)")));
- (PresenterArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterArrow_coreEither<id, id> *)a b:(PresenterArrow_coreEither<id, id> *)b c:(PresenterArrow_coreEither<id, id> *)c d:(PresenterArrow_coreEither<id, id> *)d e:(PresenterArrow_coreEither<id, id> *)e transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:transform:)")));
- (PresenterArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterArrow_coreEither<id, id> *)a b:(PresenterArrow_coreEither<id, id> *)b c:(PresenterArrow_coreEither<id, id> *)c d:(PresenterArrow_coreEither<id, id> *)d e:(PresenterArrow_coreEither<id, id> *)e f:(PresenterArrow_coreEither<id, id> *)f g:(PresenterArrow_coreEither<id, id> *)g transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:g:transform:)")));
- (PresenterArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterArrow_coreEither<id, id> *)a b:(PresenterArrow_coreEither<id, id> *)b c:(PresenterArrow_coreEither<id, id> *)c d:(PresenterArrow_coreEither<id, id> *)d e:(PresenterArrow_coreEither<id, id> *)e f:(PresenterArrow_coreEither<id, id> *)f g:(PresenterArrow_coreEither<id, id> *)g h:(PresenterArrow_coreEither<id, id> *)h transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:g:h:transform:)")));
- (PresenterArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterArrow_coreEither<id, id> *)a b:(PresenterArrow_coreEither<id, id> *)b c:(PresenterArrow_coreEither<id, id> *)c d:(PresenterArrow_coreEither<id, id> *)d e:(PresenterArrow_coreEither<id, id> *)e f:(PresenterArrow_coreEither<id, id> *)f g:(PresenterArrow_coreEither<id, id> *)g h:(PresenterArrow_coreEither<id, id> *)h i:(PresenterArrow_coreEither<id, id> *)i transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:g:h:i:transform:)")));
- (PresenterArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterArrow_coreEither<id, id> *)a b:(PresenterArrow_coreEither<id, id> *)b c:(PresenterArrow_coreEither<id, id> *)c d:(PresenterArrow_coreEither<id, id> *)d e:(PresenterArrow_coreEither<id, id> *)e f:(PresenterArrow_coreEither<id, id> *)f g:(PresenterArrow_coreEither<id, id> *)g h:(PresenterArrow_coreEither<id, id> *)h i:(PresenterArrow_coreEither<id, id> *)i j:(PresenterArrow_coreEither<id, id> *)j transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:g:h:i:j:transform:)")));
- (PresenterArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterArrow_coreEither<id, id> *)a b:(PresenterArrow_coreEither<id, id> *)b c:(PresenterArrow_coreEither<id, id> *)c d:(PresenterArrow_coreEither<id, id> *)d e:(PresenterArrow_coreEither<id, id> *)e f:(PresenterArrow_coreEither<id, id> *)f transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:transform:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="zipOrAccumulateNonEmptyList")
*/
- (PresenterArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterArrow_coreEither<NSArray<id> *, id> *)a b:(PresenterArrow_coreEither<NSArray<id> *, id> *)b transform_:(id _Nullable (^)(id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:transform_:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="zipOrAccumulateNonEmptyList")
*/
- (PresenterArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterArrow_coreEither<NSArray<id> *, id> *)a b:(PresenterArrow_coreEither<NSArray<id> *, id> *)b c:(PresenterArrow_coreEither<NSArray<id> *, id> *)c transform_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:transform_:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="zipOrAccumulateNonEmptyList")
*/
- (PresenterArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterArrow_coreEither<NSArray<id> *, id> *)a b:(PresenterArrow_coreEither<NSArray<id> *, id> *)b c:(PresenterArrow_coreEither<NSArray<id> *, id> *)c d:(PresenterArrow_coreEither<NSArray<id> *, id> *)d transform_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:transform_:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="zipOrAccumulateNonEmptyList")
*/
- (PresenterArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterArrow_coreEither<NSArray<id> *, id> *)a b:(PresenterArrow_coreEither<NSArray<id> *, id> *)b c:(PresenterArrow_coreEither<NSArray<id> *, id> *)c d:(PresenterArrow_coreEither<NSArray<id> *, id> *)d e:(PresenterArrow_coreEither<NSArray<id> *, id> *)e transform_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:transform_:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="zipOrAccumulateNonEmptyList")
*/
- (PresenterArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterArrow_coreEither<NSArray<id> *, id> *)a b:(PresenterArrow_coreEither<NSArray<id> *, id> *)b c:(PresenterArrow_coreEither<NSArray<id> *, id> *)c d:(PresenterArrow_coreEither<NSArray<id> *, id> *)d e:(PresenterArrow_coreEither<NSArray<id> *, id> *)e f:(PresenterArrow_coreEither<NSArray<id> *, id> *)f g:(PresenterArrow_coreEither<NSArray<id> *, id> *)g transform_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:g:transform_:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="zipOrAccumulateNonEmptyList")
*/
- (PresenterArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterArrow_coreEither<NSArray<id> *, id> *)a b:(PresenterArrow_coreEither<NSArray<id> *, id> *)b c:(PresenterArrow_coreEither<NSArray<id> *, id> *)c d:(PresenterArrow_coreEither<NSArray<id> *, id> *)d e:(PresenterArrow_coreEither<NSArray<id> *, id> *)e f:(PresenterArrow_coreEither<NSArray<id> *, id> *)f g:(PresenterArrow_coreEither<NSArray<id> *, id> *)g h:(PresenterArrow_coreEither<NSArray<id> *, id> *)h transform_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:g:h:transform_:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="zipOrAccumulateNonEmptyList")
*/
- (PresenterArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterArrow_coreEither<NSArray<id> *, id> *)a b:(PresenterArrow_coreEither<NSArray<id> *, id> *)b c:(PresenterArrow_coreEither<NSArray<id> *, id> *)c d:(PresenterArrow_coreEither<NSArray<id> *, id> *)d e:(PresenterArrow_coreEither<NSArray<id> *, id> *)e f:(PresenterArrow_coreEither<NSArray<id> *, id> *)f g:(PresenterArrow_coreEither<NSArray<id> *, id> *)g h:(PresenterArrow_coreEither<NSArray<id> *, id> *)h i:(PresenterArrow_coreEither<NSArray<id> *, id> *)i transform_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:g:h:i:transform_:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="zipOrAccumulateNonEmptyList")
*/
- (PresenterArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterArrow_coreEither<NSArray<id> *, id> *)a b:(PresenterArrow_coreEither<NSArray<id> *, id> *)b c:(PresenterArrow_coreEither<NSArray<id> *, id> *)c d:(PresenterArrow_coreEither<NSArray<id> *, id> *)d e:(PresenterArrow_coreEither<NSArray<id> *, id> *)e f:(PresenterArrow_coreEither<NSArray<id> *, id> *)f g:(PresenterArrow_coreEither<NSArray<id> *, id> *)g h:(PresenterArrow_coreEither<NSArray<id> *, id> *)h i:(PresenterArrow_coreEither<NSArray<id> *, id> *)i j:(PresenterArrow_coreEither<NSArray<id> *, id> *)j transform_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:g:h:i:j:transform_:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="zipOrAccumulateNonEmptyList")
*/
- (PresenterArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterArrow_coreEither<NSArray<id> *, id> *)a b:(PresenterArrow_coreEither<NSArray<id> *, id> *)b c:(PresenterArrow_coreEither<NSArray<id> *, id> *)c d:(PresenterArrow_coreEither<NSArray<id> *, id> *)d e:(PresenterArrow_coreEither<NSArray<id> *, id> *)e f:(PresenterArrow_coreEither<NSArray<id> *, id> *)f transform_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:transform_:)")));
@end

__attribute__((swift_name("Arrow_coreSemigroup")))
@protocol PresenterArrow_coreSemigroup
@required
- (id _Nullable)appendA:(id _Nullable)a b:(id _Nullable)b __attribute__((swift_name("append(a:b:)")));
- (id _Nullable)combine:(id _Nullable)receiver b:(id _Nullable)b __attribute__((swift_name("combine(_:b:)")));
- (id _Nullable)maybeCombine:(id _Nullable)receiver b:(id _Nullable)b __attribute__((swift_name("maybeCombine(_:b:)")));
- (id _Nullable)plus:(id _Nullable)receiver b:(id _Nullable)b __attribute__((swift_name("plus(_:b:)")));
@end

__attribute__((swift_name("Arrow_coreMonoid")))
@protocol PresenterArrow_coreMonoid <PresenterArrow_coreSemigroup>
@required
- (id _Nullable)combineAllElems:(NSArray<id> *)elems __attribute__((swift_name("combineAll(elems:)"))) __attribute__((deprecated("use fold instead")));
- (id _Nullable)empty __attribute__((swift_name("empty()")));
- (id _Nullable)foldElems:(NSArray<id> *)elems __attribute__((swift_name("fold(elems:)")));
- (id _Nullable)combineAll:(id)receiver __attribute__((swift_name("combineAll(_:)"))) __attribute__((deprecated("use fold instead")));
- (id _Nullable)fold:(id)receiver __attribute__((swift_name("fold(_:)")));
@end

__attribute__((swift_name("Arrow_coreOption")))
@interface PresenterArrow_coreOption<__covariant A> : PresenterBase
@property (class, readonly, getter=companion) PresenterArrow_coreOptionCompanion *companion __attribute__((swift_name("companion")));
- (PresenterArrow_coreOption<PresenterArrow_coreIor<A, id> *> *)alignB:(PresenterArrow_coreOption<id> *)b __attribute__((swift_name("align(b:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using a simple fold, or when expression")));
- (PresenterArrow_coreOption<id> *)alignB:(PresenterArrow_coreOption<id> *)b f:(id _Nullable (^)(PresenterArrow_coreIor<A, id> *))f __attribute__((swift_name("align(b:f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using a simple fold, or when expression")));
- (BOOL)allPredicate:(PresenterBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("all(predicate:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL, or fold or map")));
- (PresenterArrow_coreOption<id> *)andValue:(PresenterArrow_coreOption<id> *)value __attribute__((swift_name("and(value:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL or flatMap")));
- (PresenterArrow_coreOption<PresenterArrow_coreOption<id> *> *)crosswalkF:(PresenterArrow_coreOption<id> *(^)(A _Nullable))f __attribute__((swift_name("crosswalk(f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL or fold")));
- (NSDictionary<id, PresenterArrow_coreOption<id> *> *)crosswalkMapF:(NSDictionary<id, id> *(^)(A _Nullable))f __attribute__((swift_name("crosswalkMap(f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL or fold")));
- (PresenterArrow_coreOption<id> * _Nullable)crosswalkNullF:(id _Nullable (^)(A _Nullable))f __attribute__((swift_name("crosswalkNull(f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL or fold")));
- (BOOL)existsPredicate:(PresenterBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("exists(predicate:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPlease use Option's member function isSome. This will be removed towards Arrow 2.0")));
- (PresenterArrow_coreOption<A> *)filterPredicate:(PresenterBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("filter(predicate:)")));
- (PresenterArrow_coreOption<A> *)filterNotPredicate:(PresenterBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("filterNot(predicate:)")));
- (A _Nullable)findOrNullPredicate:(PresenterBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("findOrNull(predicate:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer Kotlin nullable syntax instead")));
- (PresenterArrow_coreOption<id> *)flatMapF:(PresenterArrow_coreOption<id> *(^)(A _Nullable))f __attribute__((swift_name("flatMap(f:)")));
- (id _Nullable)foldIfEmpty:(id _Nullable (^)(void))ifEmpty ifSome:(id _Nullable (^)(A _Nullable))ifSome __attribute__((swift_name("fold(ifEmpty:ifSome:)")));
- (id _Nullable)foldLeftInitial:(id _Nullable)initial operation:(id _Nullable (^)(id _Nullable, A _Nullable))operation __attribute__((swift_name("foldLeft(initial:operation:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (id _Nullable)foldMapMB:(id<PresenterArrow_coreMonoid>)MB f:(id _Nullable (^)(A _Nullable))f __attribute__((swift_name("foldMap(MB:f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (A _Nullable)getOrNull __attribute__((swift_name("getOrNull()")));
- (BOOL)isDefined __attribute__((swift_name("isDefined()"))) __attribute__((deprecated("Duplicated API. Please use Option's member function isSome. This will be removed towards Arrow 2.0")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()"))) __attribute__((deprecated("Duplicated API. Please use Option's member function isNone. This will be removed towards Arrow 2.0")));
- (BOOL)isNone __attribute__((swift_name("isNone()")));
- (BOOL)isNotEmpty __attribute__((swift_name("isNotEmpty()"))) __attribute__((deprecated("Duplicated API. Please use Option's member function isSome. This will be removed towards Arrow 2.0")));
- (BOOL)isSome __attribute__((swift_name("isSome()")));
- (BOOL)isSomePredicate:(PresenterBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("isSome(predicate:)")));
- (PresenterArrow_coreOption<id> *)mapF:(id _Nullable (^)(A _Nullable))f __attribute__((swift_name("map(f:)")));
- (PresenterArrow_coreOption<id> *)mapNotNullF:(id _Nullable (^)(A _Nullable))f __attribute__((swift_name("mapNotNull(f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL, or fold or map")));
- (BOOL)nonEmpty __attribute__((swift_name("nonEmpty()"))) __attribute__((deprecated("Duplicated API. Please use Option's member function isSome. This will be removed towards Arrow 2.0")));
- (PresenterArrow_coreOption<A> *)onNoneAction:(void (^)(void))action __attribute__((swift_name("onNone(action:)")));
- (PresenterArrow_coreOption<A> *)onSomeAction:(void (^)(A _Nullable))action __attribute__((swift_name("onSome(action:)")));
- (A _Nullable)orNull __attribute__((swift_name("orNull()"))) __attribute__((deprecated("orNull is being renamed to getOrNull to be more consistent with the Kotlin Standard Library naming")));
- (PresenterArrow_coreOption<PresenterKotlinPair<A, id> *> *)padZipOther:(PresenterArrow_coreOption<id> *)other __attribute__((swift_name("padZip(other:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using a simple fold, or when expression")));
- (PresenterArrow_coreOption<id> *)padZipOther:(PresenterArrow_coreOption<id> *)other f:(id _Nullable (^)(A _Nullable, id _Nullable))f __attribute__((swift_name("padZip(other:f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using a simple fold, or when expression")));
- (PresenterArrow_coreOption<PresenterKotlinPair<id, A> *> *)pairLeftLeft:(id _Nullable)left __attribute__((swift_name("pairLeft(left:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL or map")));
- (PresenterArrow_coreOption<PresenterKotlinPair<A, id> *> *)pairRightRight:(id _Nullable)right __attribute__((swift_name("pairRight(right:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL or map")));
- (id _Nullable)reduceOrNullInitial:(id _Nullable (^)(A _Nullable))initial operation:(id _Nullable (^)(id _Nullable, A _Nullable))operation __attribute__((swift_name("reduceOrNull(initial:operation:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (PresenterArrow_coreEval<id> *)reduceRightEvalOrNullInitial:(id _Nullable (^)(A _Nullable))initial operation:(PresenterArrow_coreEval<id> *(^)(A _Nullable, PresenterArrow_coreEval<id> *))operation __attribute__((swift_name("reduceRightEvalOrNull(initial:operation:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (PresenterArrow_coreOption<NSArray<id> *> *)replicateN:(int32_t)n __attribute__((swift_name("replicate(n:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL or map")));
- (PresenterArrow_coreOption<A> *)tapF:(void (^)(A _Nullable))f __attribute__((swift_name("tap(f:)"))) __attribute__((deprecated("tap is being renamed to onNone to be more consistent with the Kotlin Standard Library naming")));
- (PresenterArrow_coreOption<A> *)tapNoneF:(void (^)(void))f __attribute__((swift_name("tapNone(f:)"))) __attribute__((deprecated("tapNone is being renamed to onNone to be more consistent with the Kotlin Standard Library naming")));
- (PresenterArrow_coreEither<id, A> *)toEitherIfEmpty:(id _Nullable (^)(void))ifEmpty __attribute__((swift_name("toEither(ifEmpty:)")));
- (NSArray<id> *)toList __attribute__((swift_name("toList()")));
- (NSString *)description __attribute__((swift_name("description()")));
- (PresenterArrow_coreEither<id, PresenterArrow_coreOption<id> *> *)traverseFa:(PresenterArrow_coreEither<id, id> *(^)(A _Nullable))fa __attribute__((swift_name("traverse(fa:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL, or explicit fold or when")));
- (PresenterArrow_coreValidated<id, PresenterArrow_coreOption<id> *> *)traverseFa_:(PresenterArrow_coreValidated<id, id> *(^)(A _Nullable))fa __attribute__((swift_name("traverse(fa_:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL, or explicit fold or when")));
- (NSArray<PresenterArrow_coreOption<id> *> *)traverseFa__:(id (^)(A _Nullable))fa __attribute__((swift_name("traverse(fa__:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL, or explicit fold or when")));
- (PresenterArrow_coreEither<id, PresenterArrow_coreOption<id> *> *)traverseEitherFa:(PresenterArrow_coreEither<id, id> *(^)(A _Nullable))fa __attribute__((swift_name("traverseEither(fa:)"))) __attribute__((deprecated("traverseEither is being renamed to traverse to simplify the Arrow API")));
- (PresenterArrow_coreValidated<id, PresenterArrow_coreOption<id> *> *)traverseValidatedFa:(PresenterArrow_coreValidated<id, id> *(^)(A _Nullable))fa __attribute__((swift_name("traverseValidated(fa:)"))) __attribute__((deprecated("traverseValidated is being renamed to traverse to simplify the Arrow API")));
- (PresenterArrow_coreOption<PresenterKotlinUnit *> *)void __attribute__((swift_name("void()"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nReplace with map with Unit")));
- (PresenterArrow_coreOption<PresenterKotlinPair<A, id> *> *)zipOther:(PresenterArrow_coreOption<id> *)other __attribute__((swift_name("zip(other:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
- (PresenterArrow_coreOption<id> *)zipB:(PresenterArrow_coreOption<id> *)b map:(id _Nullable (^)(A _Nullable, id _Nullable))map __attribute__((swift_name("zip(b:map:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
- (PresenterArrow_coreOption<id> *)zipB:(PresenterArrow_coreOption<id> *)b c:(PresenterArrow_coreOption<id> *)c map:(id _Nullable (^)(A _Nullable, id _Nullable, id _Nullable))map __attribute__((swift_name("zip(b:c:map:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
- (PresenterArrow_coreOption<id> *)zipB:(PresenterArrow_coreOption<id> *)b c:(PresenterArrow_coreOption<id> *)c d:(PresenterArrow_coreOption<id> *)d map:(id _Nullable (^)(A _Nullable, id _Nullable, id _Nullable, id _Nullable))map __attribute__((swift_name("zip(b:c:d:map:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
- (PresenterArrow_coreOption<id> *)zipB:(PresenterArrow_coreOption<id> *)b c:(PresenterArrow_coreOption<id> *)c d:(PresenterArrow_coreOption<id> *)d e:(PresenterArrow_coreOption<id> *)e map:(id _Nullable (^)(A _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))map __attribute__((swift_name("zip(b:c:d:e:map:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
- (PresenterArrow_coreOption<id> *)zipB:(PresenterArrow_coreOption<id> *)b c:(PresenterArrow_coreOption<id> *)c d:(PresenterArrow_coreOption<id> *)d e:(PresenterArrow_coreOption<id> *)e f:(PresenterArrow_coreOption<id> *)f map:(id _Nullable (^)(A _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))map __attribute__((swift_name("zip(b:c:d:e:f:map:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
- (PresenterArrow_coreOption<id> *)zipB:(PresenterArrow_coreOption<id> *)b c:(PresenterArrow_coreOption<id> *)c d:(PresenterArrow_coreOption<id> *)d e:(PresenterArrow_coreOption<id> *)e f:(PresenterArrow_coreOption<id> *)f g:(PresenterArrow_coreOption<id> *)g map:(id _Nullable (^)(A _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))map __attribute__((swift_name("zip(b:c:d:e:f:g:map:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
- (PresenterArrow_coreOption<id> *)zipB:(PresenterArrow_coreOption<id> *)b c:(PresenterArrow_coreOption<id> *)c d:(PresenterArrow_coreOption<id> *)d e:(PresenterArrow_coreOption<id> *)e f:(PresenterArrow_coreOption<id> *)f g:(PresenterArrow_coreOption<id> *)g h:(PresenterArrow_coreOption<id> *)h map:(id _Nullable (^)(A _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))map __attribute__((swift_name("zip(b:c:d:e:f:g:h:map:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
- (PresenterArrow_coreOption<id> *)zipB:(PresenterArrow_coreOption<id> *)b c:(PresenterArrow_coreOption<id> *)c d:(PresenterArrow_coreOption<id> *)d e:(PresenterArrow_coreOption<id> *)e f:(PresenterArrow_coreOption<id> *)f g:(PresenterArrow_coreOption<id> *)g h:(PresenterArrow_coreOption<id> *)h i:(PresenterArrow_coreOption<id> *)i map:(id _Nullable (^)(A _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))map __attribute__((swift_name("zip(b:c:d:e:f:g:h:i:map:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
- (PresenterArrow_coreOption<id> *)zipB:(PresenterArrow_coreOption<id> *)b c:(PresenterArrow_coreOption<id> *)c d:(PresenterArrow_coreOption<id> *)d e:(PresenterArrow_coreOption<id> *)e f:(PresenterArrow_coreOption<id> *)f g:(PresenterArrow_coreOption<id> *)g h:(PresenterArrow_coreOption<id> *)h i:(PresenterArrow_coreOption<id> *)i j:(PresenterArrow_coreOption<id> *)j map:(id _Nullable (^)(A _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))map __attribute__((swift_name("zip(b:c:d:e:f:g:h:i:j:map:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
@end

__attribute__((swift_name("Arrow_coreValidated")))
@interface PresenterArrow_coreValidated<__covariant E, __covariant A> : PresenterBase
@property (class, readonly, getter=companion) PresenterArrow_coreValidatedCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)allPredicate:(PresenterBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("all(predicate:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse fold on Either after refactoring")));
- (id _Nullable)bifoldLeftC:(id _Nullable)c fe:(id _Nullable (^)(id _Nullable, E _Nullable))fe fa:(id _Nullable (^)(id _Nullable, A _Nullable))fa __attribute__((swift_name("bifoldLeft(c:fe:fa:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (id _Nullable)bifoldMapMN:(id<PresenterArrow_coreMonoid>)MN g:(id _Nullable (^)(E _Nullable))g f:(id _Nullable (^)(A _Nullable))f __attribute__((swift_name("bifoldMap(MN:g:f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (PresenterArrow_coreValidated<id, id> *)bimapFe:(id _Nullable (^)(E _Nullable))fe fa:(id _Nullable (^)(A _Nullable))fa __attribute__((swift_name("bimap(fe:fa:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse map and mapLeft on Either after refactoring")));
- (NSArray<PresenterArrow_coreValidated<id, id> *> *)bitraverseFe:(id (^)(E _Nullable))fe fa:(id (^)(A _Nullable))fa __attribute__((swift_name("bitraverse(fe:fa:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicit fold instead")));
- (PresenterArrow_coreEither<id, PresenterArrow_coreValidated<id, id> *> *)bitraverseEitherFe:(PresenterArrow_coreEither<id, id> *(^)(E _Nullable))fe fa:(PresenterArrow_coreEither<id, id> *(^)(A _Nullable))fa __attribute__((swift_name("bitraverseEither(fe:fa:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicit fold instead")));
- (PresenterArrow_coreValidated<id, id> * _Nullable)bitraverseNullableFe:(id _Nullable (^)(E _Nullable))fe fa:(id _Nullable (^)(A _Nullable))fa __attribute__((swift_name("bitraverseNullable(fe:fa:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicit fold instead")));
- (PresenterArrow_coreOption<PresenterArrow_coreValidated<id, id> *> *)bitraverseOptionFe:(PresenterArrow_coreOption<id> *(^)(E _Nullable))fe fa:(PresenterArrow_coreOption<id> *(^)(A _Nullable))fa __attribute__((swift_name("bitraverseOption(fe:fa:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicit fold instead")));
- (BOOL)existPredicate:(PresenterBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("exist(predicate:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse isRight on Either after refactoring")));
- (A _Nullable)findOrNullPredicate:(PresenterBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("findOrNull(predicate:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse getOrNull and takeIf on Either after refactoring")));
- (id _Nullable)foldFe:(id _Nullable (^)(E _Nullable))fe fa:(id _Nullable (^)(A _Nullable))fa __attribute__((swift_name("fold(fe:fa:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse fold on Either after refactoring")));
- (id _Nullable)foldLeftB:(id _Nullable)b f:(id _Nullable (^)(id _Nullable, A _Nullable))f __attribute__((swift_name("foldLeft(b:f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse fold on Either after refactoring")));
- (id _Nullable)foldMapMB:(id<PresenterArrow_coreMonoid>)MB f:(id _Nullable (^)(A _Nullable))f __attribute__((swift_name("foldMap(MB:f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse fold on Either after refactoring instead")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse isRight on Either after refactoring")));
- (BOOL)isNotEmpty __attribute__((swift_name("isNotEmpty()"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse isRight on Either after refactoring")));
- (PresenterArrow_coreValidated<E, id> *)mapF:(id _Nullable (^)(A _Nullable))f __attribute__((swift_name("map(f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse map on Either after refactoring")));
- (PresenterArrow_coreValidated<id, A> *)mapLeftF:(id _Nullable (^)(E _Nullable))f __attribute__((swift_name("mapLeft(f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse mapLeft on Either after refactoring")));
- (PresenterArrow_coreValidated<A, E> *)swap __attribute__((swift_name("swap()"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse swap on Either after refactoring")));
- (PresenterArrow_coreValidated<E, A> *)tapF:(void (^)(A _Nullable))f __attribute__((swift_name("tap(f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse onRight on Either after refactoring")));
- (PresenterArrow_coreValidated<E, A> *)tapInvalidF:(void (^)(E _Nullable))f __attribute__((swift_name("tapInvalid(f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse onLeft on Either after refactoring")));
- (PresenterArrow_coreEither<E, A> *)toEither __attribute__((swift_name("toEither()"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nDrop this call after refactoring")));
- (NSArray<id> *)toList __attribute__((swift_name("toList()"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse fold instead")));
- (PresenterArrow_coreOption<A> *)toOption __attribute__((swift_name("toOption()"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse getOrNone on Either after refactoring")));
- (NSString *)description __attribute__((swift_name("description()")));
- (PresenterArrow_coreValidated<NSArray<id> *, A> *)toValidatedNel __attribute__((swift_name("toValidatedNel()"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse toEitherNel directly instead")));
- (PresenterArrow_coreEither<id, PresenterArrow_coreValidated<E, id> *> *)traverseFa:(PresenterArrow_coreEither<id, id> *(^)(A _Nullable))fa __attribute__((swift_name("traverse(fa:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Either DSL, or explicit fold or when")));
- (PresenterArrow_coreOption<PresenterArrow_coreValidated<E, id> *> *)traverseFa_:(PresenterArrow_coreOption<id> *(^)(A _Nullable))fa __attribute__((swift_name("traverse(fa_:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Either DSL, or explicit fold or when")));
- (NSArray<PresenterArrow_coreValidated<E, id> *> *)traverseFa__:(id (^)(A _Nullable))fa __attribute__((swift_name("traverse(fa__:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Either DSL, or explicit fold or when")));
- (PresenterArrow_coreEither<id, PresenterArrow_coreValidated<E, id> *> *)traverseEitherFa:(PresenterArrow_coreEither<id, id> *(^)(A _Nullable))fa __attribute__((swift_name("traverseEither(fa:)"))) __attribute__((deprecated("traverseEither is being renamed to traverse to simplify the Arrow API")));
- (PresenterArrow_coreValidated<E, id> * _Nullable)traverseNullableFa:(id _Nullable (^)(A _Nullable))fa __attribute__((swift_name("traverseNullable(fa:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse orNull() and Kotlin nullable types")));
- (PresenterArrow_coreOption<PresenterArrow_coreValidated<E, id> *> *)traverseOptionFa:(PresenterArrow_coreOption<id> *(^)(A _Nullable))fa __attribute__((swift_name("traverseOption(fa:)"))) __attribute__((deprecated("traverseOption is being renamed to traverse to simplify the Arrow API")));
- (PresenterArrow_coreValidated<E, PresenterKotlinUnit *> *)void __attribute__((swift_name("void()"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse map on Either after refactoring instead")));
- (PresenterArrow_coreValidated<id, id> *)withEitherF:(PresenterArrow_coreEither<id, id> *(^)(PresenterArrow_coreEither<E, A> *))f __attribute__((swift_name("withEither(f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse Either directly instead")));
@property (readonly) BOOL isInvalid __attribute__((swift_name("isInvalid"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse isLeft on Either after refactoring")));
@property (readonly) BOOL isValid __attribute__((swift_name("isValid"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse isRight on Either after refactoring")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Arrow_coreIorCompanion")))
@interface PresenterArrow_coreIorCompanion : PresenterBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PresenterArrow_coreIorCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreIor<NSArray<id> *, id> *)bothNelA:(id _Nullable)a b:(id _Nullable)b __attribute__((swift_name("bothNel(a:b:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreIor<id, id> * _Nullable)fromNullablesA:(id _Nullable)a b:(id _Nullable)b __attribute__((swift_name("fromNullables(a:b:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreIor<NSArray<id> *, id> *)leftNelA:(id _Nullable)a __attribute__((swift_name("leftNel(a:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreIor<id, id> *(^)(PresenterArrow_coreIor<id, id> *))liftFa:(id _Nullable (^)(id _Nullable))fa fb:(id _Nullable (^)(id _Nullable))fb __attribute__((swift_name("lift(fa:fb:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicitly creating lambdas")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreIor<id, id> *(^)(PresenterArrow_coreIor<id, id> *))liftF:(id _Nullable (^)(id _Nullable))f __attribute__((swift_name("lift(f:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicitly creating lambdas")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinPair")))
@interface PresenterKotlinPair<__covariant A, __covariant B> : PresenterBase
- (instancetype)initWithFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("init(first:second:)"))) __attribute__((objc_designated_initializer));
- (PresenterKotlinPair<A, B> *)doCopyFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("doCopy(first:second:)")));
- (BOOL)equalsOther:(id _Nullable)other __attribute__((swift_name("equals(other:)")));
- (int32_t)hashCode __attribute__((swift_name("hashCode()")));
- (NSString *)toString __attribute__((swift_name("toString()")));
@property (readonly) A _Nullable first __attribute__((swift_name("first")));
@property (readonly) B _Nullable second __attribute__((swift_name("second")));
@end

__attribute__((swift_name("KotlinIterator")))
@protocol PresenterKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Arrow_coreOptionCompanion")))
@interface PresenterArrow_coreOptionCompanion : PresenterBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PresenterArrow_coreOptionCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
 *   kotlin.jvm.JvmName(name="tryCatchOrNone")
*/
- (PresenterArrow_coreOption<id> *)catchF:(id _Nullable (^)(void))f __attribute__((swift_name("catch(f:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
 *   kotlin.jvm.JvmName(name="tryCatch")
*/
- (PresenterArrow_coreOption<id> *)catchRecover:(PresenterArrow_coreOption<id> *(^)(PresenterKotlinThrowable *))recover f:(id _Nullable (^)(void))f __attribute__((swift_name("catch(recover:f:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreOption<id> *)fromNullableA:(id _Nullable)a __attribute__((swift_name("fromNullable(a:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreOption<id> *)invokeA:(id _Nullable)a __attribute__((swift_name("invoke(a:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreOption<id> *(^)(PresenterArrow_coreOption<id> *))liftF:(id _Nullable (^)(id _Nullable))f __attribute__((swift_name("lift(f:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicitly creating lambdas")));
@end

__attribute__((swift_name("Arrow_coreEval")))
@interface PresenterArrow_coreEval<__covariant A> : PresenterBase
@property (class, readonly, getter=companion) PresenterArrow_coreEvalCompanion *companion __attribute__((swift_name("companion")));
- (PresenterArrow_coreEval<id> *)coflatMapF:(id _Nullable (^)(PresenterArrow_coreEval<A> *))f __attribute__((swift_name("coflatMap(f:)")));
- (PresenterArrow_coreEval<id> *)flatMapF:(PresenterArrow_coreEval<id> *(^)(A _Nullable))f __attribute__((swift_name("flatMap(f:)")));
- (PresenterArrow_coreEval<id> *)mapF:(id _Nullable (^)(A _Nullable))f __attribute__((swift_name("map(f:)")));
- (PresenterArrow_coreEval<A> *)memoize __attribute__((swift_name("memoize()")));
- (NSString *)description __attribute__((swift_name("description()")));
- (A _Nullable)value __attribute__((swift_name("value()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Arrow_coreValidatedCompanion")))
@interface PresenterArrow_coreValidatedCompanion : PresenterBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PresenterArrow_coreValidatedCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
 *   kotlin.jvm.JvmName(name="tryCatch")
*/
- (PresenterArrow_coreValidated<PresenterKotlinThrowable *, id> *)catchF:(id _Nullable (^)(void))f __attribute__((swift_name("catch(f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse Either.catch instead")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
 *   kotlin.jvm.JvmName(name="tryCatch")
*/
- (PresenterArrow_coreValidated<id, id> *)catchRecover:(id _Nullable (^)(PresenterKotlinThrowable *))recover f:(id _Nullable (^)(void))f __attribute__((swift_name("catch(recover:f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse Either.catch and mapLeft instead")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreValidated<NSArray<PresenterKotlinThrowable *> *, id> *)catchNelF:(id _Nullable (^)(void))f __attribute__((swift_name("catchNel(f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse Either.catch and toEitherNel instead")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreValidated<id, id> *)fromEitherE:(PresenterArrow_coreEither<id, id> *)e __attribute__((swift_name("fromEither(e:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\n")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreValidated<id, id> *)fromNullableValue:(id _Nullable)value ifNull:(id _Nullable (^)(void))ifNull __attribute__((swift_name("fromNullable(value:ifNull:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer Kotlin nullable syntax, or ensureNotNull inside Either DSL")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreValidated<id, id> *)fromOptionO:(PresenterArrow_coreOption<id> *)o ifNone:(id _Nullable (^)(void))ifNone __attribute__((swift_name("fromOption(o:ifNone:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using toEither on Option instead")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreValidated<NSArray<id> *, id> *)invalidNelE:(id _Nullable)e __attribute__((swift_name("invalidNel(e:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse leftNel instead to construct the equivalent Either value")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreValidated<id, id> *(^)(PresenterArrow_coreValidated<id, id> *))liftF:(id _Nullable (^)(id _Nullable))f __attribute__((swift_name("lift(f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer creating explicit lambdas instead")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreValidated<id, id> *(^)(PresenterArrow_coreValidated<id, id> *))liftFl:(id _Nullable (^)(id _Nullable))fl fr:(id _Nullable (^)(id _Nullable))fr __attribute__((swift_name("lift(fl:fr:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer creating explicit lambdas instead")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreValidated<NSArray<id> *, id> *)validNelA:(id _Nullable)a __attribute__((swift_name("validNel(a:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse right instead to construct the equivalent Either value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Arrow_coreEvalCompanion")))
@interface PresenterArrow_coreEvalCompanion : PresenterBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PresenterArrow_coreEvalCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreEvalAlways<id> *)alwaysF:(id _Nullable (^)(void))f __attribute__((swift_name("always(f:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreEval<id> *)deferF:(PresenterArrow_coreEval<id> *(^)(void))f __attribute__((swift_name("defer(f:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreEvalLater<id> *)laterF:(id _Nullable (^)(void))f __attribute__((swift_name("later(f:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreEval<id> *)nowA:(id _Nullable)a __attribute__((swift_name("now(a:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterArrow_coreEval<PresenterKotlinNothing *> *)raiseT:(PresenterKotlinThrowable *)t __attribute__((swift_name("raise(t:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Arrow_coreEvalAlways")))
@interface PresenterArrow_coreEvalAlways<__covariant A> : PresenterArrow_coreEval<A>
- (instancetype)initWithF:(A _Nullable (^)(void))f __attribute__((swift_name("init(f:)"))) __attribute__((objc_designated_initializer));
- (PresenterArrow_coreEvalAlways<A> *)doCopyF:(A _Nullable (^)(void))f __attribute__((swift_name("doCopy(f:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (PresenterArrow_coreEval<A> *)memoize __attribute__((swift_name("memoize()")));
- (NSString *)description __attribute__((swift_name("description()")));
- (A _Nullable)value __attribute__((swift_name("value()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Arrow_coreEvalLater")))
@interface PresenterArrow_coreEvalLater<__covariant A> : PresenterArrow_coreEval<A>
- (instancetype)initWithF:(A _Nullable (^)(void))f __attribute__((swift_name("init(f:)"))) __attribute__((objc_designated_initializer));
- (PresenterArrow_coreEvalLater<A> *)doCopyF:(A _Nullable (^)(void))f __attribute__((swift_name("doCopy(f:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (PresenterArrow_coreEval<A> *)memoize __attribute__((swift_name("memoize()")));
- (NSString *)description __attribute__((swift_name("description()")));
- (A _Nullable)value __attribute__((swift_name("value()")));
@property (readonly, getter=value_) A _Nullable value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinNothing")))
@interface PresenterKotlinNothing : PresenterBase
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
