#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class PresenterBaseDispatcherProvider, PresenterBaseKotlinx_coroutines_coreCoroutineDispatcher, PresenterBaseModelEventViewTag, PresenterBaseModelEvent, PresenterBaseModelProviderError, PresenterBaseArrow_coreEither<__covariant A, __covariant B>, PresenterBaseKotlinUnit, PresenterBaseModelObj, PresenterBaseArrow_coreIor<__covariant A, __covariant B>, PresenterBaseModelLevel, PresenterBaseKoferoObj, PresenterBaseKotlinException, PresenterBaseInteractorImpl<V, P>, PresenterBaseModelIncorrectCount, PresenterBaseModelMove, PresenterBaseModelCharacter, PresenterBaseGamePresenterImpl, PresenterBaseModelGame, PresenterBasePresenterImpl<V>, PresenterBaseKotlinAbstractCoroutineContextElement, PresenterBaseKotlinx_coroutines_coreCoroutineDispatcherKey, PresenterBaseKotlinEnumCompanion, PresenterBaseKotlinEnum<E>, PresenterBaseKotlinArray<T>, PresenterBaseModelEventValue, PresenterBaseArrow_coreEitherCompanion, PresenterBaseArrow_coreOption<__covariant A>, PresenterBaseArrow_coreValidated<__covariant E, __covariant A>, PresenterBaseArrow_coreIorCompanion, PresenterBaseKotlinPair<__covariant A, __covariant B>, PresenterBaseKotlinThrowable, PresenterBaseKotlinRuntimeException, PresenterBaseKotlinIllegalStateException, PresenterBaseKotlinAbstractCoroutineContextKey<B, E>, PresenterBaseArrow_coreOptionCompanion, PresenterBaseArrow_coreEval<__covariant A>, PresenterBaseArrow_coreValidatedCompanion, PresenterBaseArrow_coreEvalCompanion, PresenterBaseArrow_coreEvalAlways<__covariant A>, PresenterBaseArrow_coreEvalLater<__covariant A>, PresenterBaseKotlinNothing;

@protocol PresenterBaseStateLogger, PresenterBaseStateProvider, PresenterBaseLoggingProvider, PresenterBaseProvider, PresenterBaseView, PresenterBaseInteractor, PresenterBaseStateReducer, PresenterBaseRouter, PresenterBasePresenter, PresenterBaseCharacterInteractor, PresenterBaseCharacterPresenter, PresenterBaseCharacterView, PresenterBaseImageProvider, PresenterBaseGameInteractor, PresenterBaseKotlinCoroutineContext, PresenterBaseGameView, PresenterBaseGamePresenter, PresenterBaseModelError, PresenterBaseHomeInteractor, PresenterBaseHomePresenter, PresenterBaseHomeView, PresenterBaseFavoritesProvider, PresenterBaseMovePresenter, PresenterBaseMoveView, PresenterBaseRootPresenter, PresenterBaseRootView, PresenterBaseKotlinCoroutineContextKey, PresenterBaseKotlinCoroutineContextElement, PresenterBaseKotlinContinuation, PresenterBaseKotlinContinuationInterceptor, PresenterBaseKotlinx_coroutines_coreRunnable, PresenterBaseKotlinComparable, PresenterBaseArrow_coreMonoid, PresenterBaseArrow_coreSemigroup, PresenterBaseKotlinIterator;

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
@interface PresenterBaseBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface PresenterBaseBase (PresenterBaseBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface PresenterBaseMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface PresenterBaseMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorPresenterBaseKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface PresenterBaseNumber : NSNumber
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
@interface PresenterBaseByte : PresenterBaseNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface PresenterBaseUByte : PresenterBaseNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface PresenterBaseShort : PresenterBaseNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface PresenterBaseUShort : PresenterBaseNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface PresenterBaseInt : PresenterBaseNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface PresenterBaseUInt : PresenterBaseNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface PresenterBaseLong : PresenterBaseNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface PresenterBaseULong : PresenterBaseNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface PresenterBaseFloat : PresenterBaseNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface PresenterBaseDouble : PresenterBaseNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface PresenterBaseBoolean : PresenterBaseNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end


/**
 * @note annotations
 *   kotlinx.coroutines.DelicateCoroutinesApi
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DispatcherProvider")))
@interface PresenterBaseDispatcherProvider : PresenterBaseBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)dispatcherProvider __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PresenterBaseDispatcherProvider *shared __attribute__((swift_name("shared")));
@property (readonly, getter=default) PresenterBaseKotlinx_coroutines_coreCoroutineDispatcher *default_ __attribute__((swift_name("default_")));
@property (readonly) PresenterBaseKotlinx_coroutines_coreCoroutineDispatcher *ui __attribute__((swift_name("ui")));
@end

__attribute__((swift_name("Router")))
@protocol PresenterBaseRouter
@required
- (BOOL)routeToView:(PresenterBaseModelEventViewTag *)view uid:(int32_t)uid __attribute__((swift_name("routeTo(view:uid:)")));
@end

__attribute__((swift_name("StateLogger")))
@protocol PresenterBaseStateLogger
@required
- (NSDictionary<PresenterBaseLong *, PresenterBaseModelEvent *> *)getStateMap __attribute__((swift_name("getStateMap()")));
- (BOOL)logStateUnixTime:(int64_t)unixTime event:(PresenterBaseModelEvent *)event __attribute__((swift_name("logState(unixTime:event:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("StateLoggerImpl")))
@interface PresenterBaseStateLoggerImpl : PresenterBaseBase <PresenterBaseStateLogger>
- (instancetype)initWithStateRepository:(id<PresenterBaseStateProvider>)stateRepository loggingProvider:(id<PresenterBaseLoggingProvider>)loggingProvider __attribute__((swift_name("init(stateRepository:loggingProvider:)"))) __attribute__((objc_designated_initializer));
- (NSDictionary<PresenterBaseLong *, PresenterBaseModelEvent *> *)getStateMap __attribute__((swift_name("getStateMap()")));
- (BOOL)logStateUnixTime:(int64_t)unixTime event:(PresenterBaseModelEvent *)event __attribute__((swift_name("logState(unixTime:event:)")));
@end

__attribute__((swift_name("StateProvider")))
@protocol PresenterBaseStateProvider
@required
- (PresenterBaseArrow_coreEither<PresenterBaseModelProviderError *, NSDictionary<PresenterBaseLong *, PresenterBaseModelEvent *> *> *)get __attribute__((swift_name("get()")));
- (PresenterBaseArrow_coreEither<PresenterBaseModelProviderError *, PresenterBaseKotlinUnit *> *)saveMap:(NSDictionary<PresenterBaseLong *, PresenterBaseModelEvent *> *)map __attribute__((swift_name("save(map:)")));
@end

__attribute__((swift_name("StateReducer")))
@protocol PresenterBaseStateReducer
@required
- (BOOL)authorizeEvent:(PresenterBaseModelEvent *)event stateMap:(NSDictionary<PresenterBaseLong *, PresenterBaseModelEvent *> *)stateMap __attribute__((swift_name("authorize(event:stateMap:)")));
- (PresenterBaseModelEvent *)reduceStateMap:(NSDictionary<PresenterBaseLong *, PresenterBaseModelEvent *> *)stateMap __attribute__((swift_name("reduce(stateMap:)")));
@end

__attribute__((swift_name("Provider")))
@protocol PresenterBaseProvider
@required
- (PresenterBaseArrow_coreIor<PresenterBaseModelProviderError *, NSArray<PresenterBaseModelObj *> *> *)getIds:(NSArray<PresenterBaseInt *> *)ids __attribute__((swift_name("get(ids:)")));
@end

__attribute__((swift_name("FavoritesProvider")))
@protocol PresenterBaseFavoritesProvider <PresenterBaseProvider>
@required
- (PresenterBaseArrow_coreEither<PresenterBaseModelProviderError *, PresenterBaseKotlinUnit *> *)deleteItem:(PresenterBaseModelObj *)item __attribute__((swift_name("delete(item:)")));
- (PresenterBaseArrow_coreEither<PresenterBaseModelProviderError *, PresenterBaseKotlinUnit *> *)saveItem:(PresenterBaseModelObj *)item __attribute__((swift_name("save(item:)")));
@end

__attribute__((swift_name("ImageProvider")))
@protocol PresenterBaseImageProvider
@required
- (PresenterBaseArrow_coreEither<PresenterBaseModelProviderError *, id> *)getUrl:(NSString *)url __attribute__((swift_name("get(url:)")));
@end

__attribute__((swift_name("LoggingProvider")))
@protocol PresenterBaseLoggingProvider
@required
- (void)logLevel:(PresenterBaseModelLevel *)level logTag:(NSString *)logTag message:(NSString *)message __attribute__((swift_name("log(level:logTag:message:)")));
@end

__attribute__((swift_name("Interactor")))
@protocol PresenterBaseInteractor
@required
- (void)setViewView:(id<PresenterBaseView>)view __attribute__((swift_name("setView(view:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
- (void)viewPaused __attribute__((swift_name("viewPaused()")));
- (void)viewResumed __attribute__((swift_name("viewResumed()")));
@end

__attribute__((swift_name("KoferoObj")))
@interface PresenterBaseKoferoObj : PresenterBaseBase
- (instancetype)initWithLoggingProvider:(id<PresenterBaseLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer));
- (void)shutdown __attribute__((swift_name("shutdown()")));
@end

__attribute__((swift_name("InteractorImpl")))
@interface PresenterBaseInteractorImpl<V, P> : PresenterBaseKoferoObj <PresenterBaseInteractor>
- (instancetype)initWithPresenter:(P)presenter stateLogger:(id<PresenterBaseStateLogger>)stateLogger stateReducer:(id<PresenterBaseStateReducer>)stateReducer router:(id<PresenterBaseRouter>)router loggingProvider:(id<PresenterBaseLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(presenter:stateLogger:stateReducer:router:loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithLoggingProvider:(id<PresenterBaseLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (void)setViewView:(V)view __attribute__((swift_name("setView(view:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
- (void)viewPaused __attribute__((swift_name("viewPaused()")));
- (void)viewResumed __attribute__((swift_name("viewResumed()")));
@property id<PresenterBaseRouter> router __attribute__((swift_name("router")));
@end

__attribute__((swift_name("Presenter")))
@protocol PresenterBasePresenter
@required
- (void)setViewView_:(id<PresenterBaseView>)view __attribute__((swift_name("setView(view_:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
@end

__attribute__((swift_name("PresenterImpl")))
@interface PresenterBasePresenterImpl<V> : PresenterBaseKoferoObj <PresenterBasePresenter>
- (instancetype)initWithView:(V _Nullable)view loggingProvider:(id<PresenterBaseLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(view:loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithLoggingProvider:(id<PresenterBaseLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (void)setViewView_:(V)view __attribute__((swift_name("setView(view_:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
@end

__attribute__((swift_name("View")))
@protocol PresenterBaseView
@required
- (void)errorE:(PresenterBaseKotlinException *)e __attribute__((swift_name("error(e:)")));
@end

__attribute__((swift_name("CharacterInteractor")))
@protocol PresenterBaseCharacterInteractor <PresenterBaseInteractor>
@required
- (void)setCharUidUid:(int32_t)uid __attribute__((swift_name("setCharUid(uid:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CharacterInteractorImpl")))
@interface PresenterBaseCharacterInteractorImpl : PresenterBaseInteractorImpl<id<PresenterBaseCharacterView>, id<PresenterBaseCharacterPresenter>> <PresenterBaseCharacterInteractor>
- (instancetype)initWithPresenter:(id<PresenterBaseCharacterPresenter>)presenter stateLogger:(id<PresenterBaseStateLogger>)stateLogger stateReducer:(id<PresenterBaseStateReducer>)stateReducer loggingProvider:(id<PresenterBaseLoggingProvider>)loggingProvider router:(id<PresenterBaseRouter>)router __attribute__((swift_name("init(presenter:stateLogger:stateReducer:loggingProvider:router:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPresenter:(id<PresenterBasePresenter>)presenter stateLogger:(id<PresenterBaseStateLogger>)stateLogger stateReducer:(id<PresenterBaseStateReducer>)stateReducer router:(id<PresenterBaseRouter>)router loggingProvider:(id<PresenterBaseLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(presenter:stateLogger:stateReducer:router:loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (void)setCharUidUid:(int32_t)uid __attribute__((swift_name("setCharUid(uid:)")));
- (void)setViewView:(id<PresenterBaseCharacterView>)view __attribute__((swift_name("setView(view:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
- (void)viewPaused __attribute__((swift_name("viewPaused()")));
- (void)viewResumed __attribute__((swift_name("viewResumed()")));
@end

__attribute__((swift_name("CharacterPresenter")))
@protocol PresenterBaseCharacterPresenter <PresenterBasePresenter>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)showCharId:(int32_t)id completionHandler:(void (^)(PresenterBaseArrow_coreEither<PresenterBaseModelProviderError *, PresenterBaseKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("showChar(id:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CharacterPresenterImpl")))
@interface PresenterBaseCharacterPresenterImpl : PresenterBaseBase <PresenterBaseCharacterPresenter>
- (instancetype)initWithCharProvider:(id<PresenterBaseProvider>)charProvider moveProvider:(id<PresenterBaseProvider>)moveProvider imageProvider:(id<PresenterBaseImageProvider>)imageProvider __attribute__((swift_name("init(charProvider:moveProvider:imageProvider:)"))) __attribute__((objc_designated_initializer));
- (void)setViewView_:(id<PresenterBaseCharacterView>)view __attribute__((swift_name("setView(view_:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)showCharId:(int32_t)id completionHandler:(void (^)(PresenterBaseArrow_coreEither<PresenterBaseModelIncorrectCount *, PresenterBaseKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("showChar(id:completionHandler:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
@end

__attribute__((swift_name("CharacterView")))
@protocol PresenterBaseCharacterView <PresenterBaseView>
@required
- (void)displayUrl:(NSString *)url imgBase64:(NSString *)imgBase64 __attribute__((swift_name("display(url:imgBase64:)")));
- (void)displayMoves:(NSArray<PresenterBaseModelMove *> *)moves __attribute__((swift_name("display(moves:)")));
- (void)displayCharacter:(PresenterBaseModelCharacter *)character __attribute__((swift_name("display(character:)")));
- (void)displayNotOnDiskUrl:(NSString *)url __attribute__((swift_name("displayNotOnDisk(url:)")));
@end

__attribute__((swift_name("GameInteractor")))
@protocol PresenterBaseGameInteractor <PresenterBaseInteractor>
@required
- (void)charPressedChar:(PresenterBaseModelCharacter *)char_ __attribute__((swift_name("charPressed(char:)")));
- (void)setGameUidUid:(int32_t)uid __attribute__((swift_name("setGameUid(uid:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GameInteractorImpl")))
@interface PresenterBaseGameInteractorImpl : PresenterBaseInteractorImpl<id<PresenterBaseGameView>, id<PresenterBaseGamePresenter>> <PresenterBaseGameInteractor>
- (instancetype)initWithPresenter:(PresenterBaseGamePresenterImpl *)presenter stateLogger:(id<PresenterBaseStateLogger>)stateLogger stateReducer:(id<PresenterBaseStateReducer>)stateReducer loggingProvider:(id<PresenterBaseLoggingProvider>)loggingProvider router:(id<PresenterBaseRouter>)router context:(id<PresenterBaseKotlinCoroutineContext>)context __attribute__((swift_name("init(presenter:stateLogger:stateReducer:loggingProvider:router:context:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPresenter:(id<PresenterBasePresenter>)presenter stateLogger:(id<PresenterBaseStateLogger>)stateLogger stateReducer:(id<PresenterBaseStateReducer>)stateReducer router:(id<PresenterBaseRouter>)router loggingProvider:(id<PresenterBaseLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(presenter:stateLogger:stateReducer:router:loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (void)charPressedChar:(PresenterBaseModelCharacter *)char_ __attribute__((swift_name("charPressed(char:)")));
- (void)setGameUidUid:(int32_t)uid __attribute__((swift_name("setGameUid(uid:)")));
- (void)viewResumed __attribute__((swift_name("viewResumed()")));
@end

__attribute__((swift_name("GamePresenter")))
@protocol PresenterBaseGamePresenter <PresenterBasePresenter>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)showGameId:(int32_t)id completionHandler:(void (^)(PresenterBaseArrow_coreEither<id<PresenterBaseModelError>, PresenterBaseKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("showGame(id:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GamePresenterImpl")))
@interface PresenterBaseGamePresenterImpl : PresenterBaseBase <PresenterBaseGamePresenter>
- (instancetype)initWithCharacterProvider:(id<PresenterBaseProvider>)characterProvider gameProvider:(id<PresenterBaseProvider>)gameProvider imageProvider:(id<PresenterBaseImageProvider>)imageProvider __attribute__((swift_name("init(characterProvider:gameProvider:imageProvider:)"))) __attribute__((objc_designated_initializer));
- (void)setViewView_:(id<PresenterBaseGameView>)view __attribute__((swift_name("setView(view_:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)showGameId:(int32_t)id completionHandler:(void (^)(PresenterBaseArrow_coreEither<id<PresenterBaseModelError>, PresenterBaseKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("showGame(id:completionHandler:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
@end

__attribute__((swift_name("GameView")))
@protocol PresenterBaseGameView <PresenterBaseView>
@required
- (void)displayUrl:(NSString *)url imgBase64:(NSString *)imgBase64 __attribute__((swift_name("display(url:imgBase64:)")));
- (void)displayCharacters:(NSArray<PresenterBaseModelCharacter *> *)characters __attribute__((swift_name("display(characters:)")));
- (void)displayGame:(PresenterBaseModelGame *)game __attribute__((swift_name("display(game:)")));
- (void)displayNotOnDiskUrl:(NSString *)url __attribute__((swift_name("displayNotOnDisk(url:)")));
@end

__attribute__((swift_name("HomeInteractor")))
@protocol PresenterBaseHomeInteractor <PresenterBaseInteractor>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)favPressedObj:(PresenterBaseModelObj *)obj completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("favPressed(obj:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)gamePressedGame:(PresenterBaseModelGame *)game completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("gamePressed(game:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HomeInteractorImpl")))
@interface PresenterBaseHomeInteractorImpl : PresenterBaseInteractorImpl<id<PresenterBaseHomeView>, id<PresenterBaseHomePresenter>> <PresenterBaseHomeInteractor>
- (instancetype)initWithPresenter:(id<PresenterBaseHomePresenter>)presenter stateLogger:(id<PresenterBaseStateLogger>)stateLogger stateReducer:(id<PresenterBaseStateReducer>)stateReducer loggingProvider:(id<PresenterBaseLoggingProvider>)loggingProvider router:(id<PresenterBaseRouter>)router context:(id<PresenterBaseKotlinCoroutineContext>)context __attribute__((swift_name("init(presenter:stateLogger:stateReducer:loggingProvider:router:context:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPresenter:(id<PresenterBasePresenter>)presenter stateLogger:(id<PresenterBaseStateLogger>)stateLogger stateReducer:(id<PresenterBaseStateReducer>)stateReducer router:(id<PresenterBaseRouter>)router loggingProvider:(id<PresenterBaseLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(presenter:stateLogger:stateReducer:router:loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)favPressedObj:(PresenterBaseModelObj *)obj completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("favPressed(obj:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)gamePressedGame:(PresenterBaseModelGame *)game completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("gamePressed(game:completionHandler:)")));
- (void)viewResumed __attribute__((swift_name("viewResumed()")));
@end

__attribute__((swift_name("HomePresenter")))
@protocol PresenterBaseHomePresenter <PresenterBasePresenter>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)showFavsWithCompletionHandler:(void (^)(PresenterBaseArrow_coreEither<PresenterBaseModelProviderError *, PresenterBaseKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("showFavs(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)showGamesWithCompletionHandler:(void (^)(PresenterBaseArrow_coreEither<PresenterBaseModelProviderError *, PresenterBaseKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("showGames(completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HomePresenterImpl")))
@interface PresenterBaseHomePresenterImpl : PresenterBasePresenterImpl<id<PresenterBaseHomeView>> <PresenterBaseHomePresenter>
- (instancetype)initWithGameProvider:(id<PresenterBaseProvider>)gameProvider imageProvider:(id<PresenterBaseImageProvider>)imageProvider favoritesProvider:(id<PresenterBaseFavoritesProvider>)favoritesProvider loggingProvider:(id<PresenterBaseLoggingProvider>)loggingProvider __attribute__((swift_name("init(gameProvider:imageProvider:favoritesProvider:loggingProvider:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithView:(id<PresenterBaseView> _Nullable)view loggingProvider:(id<PresenterBaseLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(view:loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (void)setViewView_:(id<PresenterBaseHomeView>)view __attribute__((swift_name("setView(view_:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)showFavsWithCompletionHandler:(void (^)(PresenterBaseArrow_coreEither<PresenterBaseModelProviderError *, PresenterBaseKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("showFavs(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)showGamesWithCompletionHandler:(void (^)(PresenterBaseArrow_coreEither<PresenterBaseModelProviderError *, PresenterBaseKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("showGames(completionHandler:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
@end

__attribute__((swift_name("HomeView")))
@protocol PresenterBaseHomeView <PresenterBaseView>
@required
- (void)displayUrl:(NSString *)url imgBase64:(NSString *)imgBase64 __attribute__((swift_name("display(url:imgBase64:)")));
- (void)displayFavsFavorites:(NSArray<PresenterBaseModelObj *> *)favorites __attribute__((swift_name("displayFavs(favorites:)")));
- (void)displayFavsErrorError:(id<PresenterBaseModelError>)error __attribute__((swift_name("displayFavsError(error:)")));
- (void)displayGamesGames:(NSArray<PresenterBaseModelGame *> *)games __attribute__((swift_name("displayGames(games:)")));
- (void)displayGamesErrorError:(id<PresenterBaseModelError>)error __attribute__((swift_name("displayGamesError(error:)")));
@end

__attribute__((swift_name("MovePresenter")))
@protocol PresenterBaseMovePresenter <PresenterBasePresenter>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MovePresenterImpl")))
@interface PresenterBaseMovePresenterImpl : PresenterBaseBase <PresenterBaseMovePresenter>
- (instancetype)initWithMoveProvider:(id<PresenterBaseProvider>)moveProvider charProvider:(id<PresenterBaseProvider>)charProvider gameProvider:(id<PresenterBaseProvider>)gameProvider imageProvider:(id<PresenterBaseImageProvider>)imageProvider __attribute__((swift_name("init(moveProvider:charProvider:gameProvider:imageProvider:)"))) __attribute__((objc_designated_initializer));
- (void)setViewView_:(id<PresenterBaseMoveView>)view __attribute__((swift_name("setView(view_:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
@end

__attribute__((swift_name("MoveView")))
@protocol PresenterBaseMoveView <PresenterBaseView>
@required
@end

__attribute__((swift_name("RootPresenter")))
@protocol PresenterBaseRootPresenter <PresenterBasePresenter>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RootPresenterImpl")))
@interface PresenterBaseRootPresenterImpl : PresenterBasePresenterImpl<id<PresenterBaseRootView>> <PresenterBaseRootPresenter>
- (instancetype)initWithGameProvider:(id<PresenterBaseProvider>)gameProvider loggingProvider:(id<PresenterBaseLoggingProvider>)loggingProvider __attribute__((swift_name("init(gameProvider:loggingProvider:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithView:(id<PresenterBaseView> _Nullable)view loggingProvider:(id<PresenterBaseLoggingProvider> _Nullable)loggingProvider logTag:(NSString *)logTag __attribute__((swift_name("init(view:loggingProvider:logTag:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (void)setViewView_:(id<PresenterBaseRootView>)view __attribute__((swift_name("setView(view_:)")));
- (void)shutdown __attribute__((swift_name("shutdown()")));
@end

__attribute__((swift_name("RootView")))
@protocol PresenterBaseRootView <PresenterBaseView>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ArrowExtensionsKt")))
@interface PresenterBaseArrowExtensionsKt : PresenterBaseBase
+ (PresenterBaseArrow_coreEither<id, id> *)buildEitherLeftLeft:(id _Nullable)left __attribute__((swift_name("buildEitherLeft(left:)")));
+ (PresenterBaseArrow_coreEither<id, id> *)buildEitherRightRight:(id _Nullable)right __attribute__((swift_name("buildEitherRight(right:)")));
+ (PresenterBaseArrow_coreIor<id, id> *)buildIorBothLeft:(id _Nullable)left right:(id _Nullable)right __attribute__((swift_name("buildIorBoth(left:right:)")));
+ (PresenterBaseArrow_coreIor<id, id> *)buildIorLeftLeft:(id _Nullable)left __attribute__((swift_name("buildIorLeft(left:)")));
+ (PresenterBaseArrow_coreIor<id, id> *)buildIorRightRight:(id _Nullable)right __attribute__((swift_name("buildIorRight(right:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UtilsKt")))
@interface PresenterBaseUtilsKt : PresenterBaseBase
+ (int64_t)millisNow __attribute__((swift_name("millisNow()")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinCoroutineContext")))
@protocol PresenterBaseKotlinCoroutineContext
@required
- (id _Nullable)foldInitial:(id _Nullable)initial operation:(id _Nullable (^)(id _Nullable, id<PresenterBaseKotlinCoroutineContextElement>))operation __attribute__((swift_name("fold(initial:operation:)")));
- (id<PresenterBaseKotlinCoroutineContextElement> _Nullable)getKey:(id<PresenterBaseKotlinCoroutineContextKey>)key __attribute__((swift_name("get(key:)")));
- (id<PresenterBaseKotlinCoroutineContext>)minusKeyKey:(id<PresenterBaseKotlinCoroutineContextKey>)key __attribute__((swift_name("minusKey(key:)")));
- (id<PresenterBaseKotlinCoroutineContext>)plusContext:(id<PresenterBaseKotlinCoroutineContext>)context __attribute__((swift_name("plus(context:)")));
@end

__attribute__((swift_name("KotlinCoroutineContextElement")))
@protocol PresenterBaseKotlinCoroutineContextElement <PresenterBaseKotlinCoroutineContext>
@required
@property (readonly) id<PresenterBaseKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinAbstractCoroutineContextElement")))
@interface PresenterBaseKotlinAbstractCoroutineContextElement : PresenterBaseBase <PresenterBaseKotlinCoroutineContextElement>
- (instancetype)initWithKey:(id<PresenterBaseKotlinCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer));
@property (readonly) id<PresenterBaseKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinContinuationInterceptor")))
@protocol PresenterBaseKotlinContinuationInterceptor <PresenterBaseKotlinCoroutineContextElement>
@required
- (id<PresenterBaseKotlinContinuation>)interceptContinuationContinuation:(id<PresenterBaseKotlinContinuation>)continuation __attribute__((swift_name("interceptContinuation(continuation:)")));
- (void)releaseInterceptedContinuationContinuation:(id<PresenterBaseKotlinContinuation>)continuation __attribute__((swift_name("releaseInterceptedContinuation(continuation:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineDispatcher")))
@interface PresenterBaseKotlinx_coroutines_coreCoroutineDispatcher : PresenterBaseKotlinAbstractCoroutineContextElement <PresenterBaseKotlinContinuationInterceptor>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithKey:(id<PresenterBaseKotlinCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) PresenterBaseKotlinx_coroutines_coreCoroutineDispatcherKey *companion __attribute__((swift_name("companion")));
- (void)dispatchContext:(id<PresenterBaseKotlinCoroutineContext>)context block:(id<PresenterBaseKotlinx_coroutines_coreRunnable>)block __attribute__((swift_name("dispatch(context:block:)")));
- (void)dispatchYieldContext:(id<PresenterBaseKotlinCoroutineContext>)context block:(id<PresenterBaseKotlinx_coroutines_coreRunnable>)block __attribute__((swift_name("dispatchYield(context:block:)")));
- (id<PresenterBaseKotlinContinuation>)interceptContinuationContinuation:(id<PresenterBaseKotlinContinuation>)continuation __attribute__((swift_name("interceptContinuation(continuation:)")));
- (BOOL)isDispatchNeededContext:(id<PresenterBaseKotlinCoroutineContext>)context __attribute__((swift_name("isDispatchNeeded(context:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (PresenterBaseKotlinx_coroutines_coreCoroutineDispatcher *)limitedParallelismParallelism:(int32_t)parallelism __attribute__((swift_name("limitedParallelism(parallelism:)")));
- (PresenterBaseKotlinx_coroutines_coreCoroutineDispatcher *)plusOther:(PresenterBaseKotlinx_coroutines_coreCoroutineDispatcher *)other __attribute__((swift_name("plus(other:)"))) __attribute__((unavailable("Operator '+' on two CoroutineDispatcher objects is meaningless. CoroutineDispatcher is a coroutine context element and `+` is a set-sum operator for coroutine contexts. The dispatcher to the right of `+` just replaces the dispatcher to the left.")));
- (void)releaseInterceptedContinuationContinuation:(id<PresenterBaseKotlinContinuation>)continuation __attribute__((swift_name("releaseInterceptedContinuation(continuation:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("KotlinComparable")))
@protocol PresenterBaseKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end

__attribute__((swift_name("KotlinEnum")))
@interface PresenterBaseKotlinEnum<E> : PresenterBaseBase <PresenterBaseKotlinComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) PresenterBaseKotlinEnumCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelEvent.ViewTag")))
@interface PresenterBaseModelEventViewTag : PresenterBaseKotlinEnum<PresenterBaseModelEventViewTag *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) PresenterBaseModelEventViewTag *homeView __attribute__((swift_name("homeView")));
@property (class, readonly) PresenterBaseModelEventViewTag *gameView __attribute__((swift_name("gameView")));
@property (class, readonly) PresenterBaseModelEventViewTag *charView __attribute__((swift_name("charView")));
+ (PresenterBaseKotlinArray<PresenterBaseModelEventViewTag *> *)values __attribute__((swift_name("values()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelEvent")))
@interface PresenterBaseModelEvent : PresenterBaseBase
- (instancetype)initWithView:(PresenterBaseModelEventViewTag *)view value:(PresenterBaseModelEventValue *)value extras:(NSDictionary<NSString *, id> *)extras __attribute__((swift_name("init(view:value:extras:)"))) __attribute__((objc_designated_initializer));
- (PresenterBaseModelEvent *)doCopyView:(PresenterBaseModelEventViewTag *)view value:(PresenterBaseModelEventValue *)value extras:(NSDictionary<NSString *, id> *)extras __attribute__((swift_name("doCopy(view:value:extras:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSDictionary<NSString *, id> *extras __attribute__((swift_name("extras")));
@property (readonly) PresenterBaseModelEventValue *value __attribute__((swift_name("value")));
@property (readonly) PresenterBaseModelEventViewTag *view __attribute__((swift_name("view")));
@end

__attribute__((swift_name("ModelError")))
@protocol PresenterBaseModelError
@required
@end

__attribute__((swift_name("ModelProviderError")))
@interface PresenterBaseModelProviderError : PresenterBaseBase <PresenterBaseModelError>
@end

__attribute__((swift_name("Arrow_coreEither")))
@interface PresenterBaseArrow_coreEither<__covariant A, __covariant B> : PresenterBaseBase
@property (class, readonly, getter=companion) PresenterBaseArrow_coreEitherCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)allPredicate:(PresenterBaseBoolean *(^)(B _Nullable))predicate __attribute__((swift_name("all(predicate:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (id _Nullable)bifoldLeftC:(id _Nullable)c f:(id _Nullable (^)(id _Nullable, A _Nullable))f g:(id _Nullable (^)(id _Nullable, B _Nullable))g __attribute__((swift_name("bifoldLeft(c:f:g:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (id _Nullable)bifoldMapMN:(id<PresenterBaseArrow_coreMonoid>)MN f:(id _Nullable (^)(A _Nullable))f g:(id _Nullable (^)(B _Nullable))g __attribute__((swift_name("bifoldMap(MN:f:g:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (PresenterBaseArrow_coreEither<id, id> *)bimapLeftOperation:(id _Nullable (^)(A _Nullable))leftOperation rightOperation:(id _Nullable (^)(B _Nullable))rightOperation __attribute__((swift_name("bimap(leftOperation:rightOperation:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Either DSL, or map + mapLeft")));
- (NSArray<PresenterBaseArrow_coreEither<id, id> *> *)bitraverseFe:(id (^)(A _Nullable))fe fa:(id (^)(B _Nullable))fa __attribute__((swift_name("bitraverse(fe:fa:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicit fold instead")));
- (PresenterBaseArrow_coreEither<id, id> * _Nullable)bitraverseNullableFl:(id _Nullable (^)(A _Nullable))fl fr:(id _Nullable (^)(B _Nullable))fr __attribute__((swift_name("bitraverseNullable(fl:fr:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicit fold instead")));
- (PresenterBaseArrow_coreOption<PresenterBaseArrow_coreEither<id, id> *> *)bitraverseOptionFl:(PresenterBaseArrow_coreOption<id> *(^)(A _Nullable))fl fr:(PresenterBaseArrow_coreOption<id> *(^)(B _Nullable))fr __attribute__((swift_name("bitraverseOption(fl:fr:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicit fold instead")));
- (PresenterBaseArrow_coreValidated<id, PresenterBaseArrow_coreEither<id, id> *> *)bitraverseValidatedFe:(PresenterBaseArrow_coreValidated<id, id> *(^)(A _Nullable))fe fa:(PresenterBaseArrow_coreValidated<id, id> *(^)(B _Nullable))fa __attribute__((swift_name("bitraverseValidated(fe:fa:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicit fold instead")));
- (BOOL)existPredicate:(PresenterBaseBoolean *(^)(B _Nullable))predicate __attribute__((swift_name("exist(predicate:)"))) __attribute__((deprecated("Facilitates the migration from Validated to Either.")));
- (BOOL)existsPredicate:(PresenterBaseBoolean *(^)(B _Nullable))predicate __attribute__((swift_name("exists(predicate:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer isRight")));
- (B _Nullable)findOrNullPredicate:(PresenterBaseBoolean *(^)(B _Nullable))predicate __attribute__((swift_name("findOrNull(predicate:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer Kotlin nullable syntax instead")));
- (id _Nullable)foldIfLeft:(id _Nullable (^)(A _Nullable))ifLeft ifRight:(id _Nullable (^)(B _Nullable))ifRight __attribute__((swift_name("fold(ifLeft:ifRight:)")));
- (id _Nullable)foldLeftInitial:(id _Nullable)initial rightOperation:(id _Nullable (^)(id _Nullable, B _Nullable))rightOperation __attribute__((swift_name("foldLeft(initial:rightOperation:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (id _Nullable)foldMapMN:(id<PresenterBaseArrow_coreMonoid>)MN f:(id _Nullable (^)(B _Nullable))f __attribute__((swift_name("foldMap(MN:f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (PresenterBaseArrow_coreOption<B> *)getOrNone __attribute__((swift_name("getOrNone()")));
- (B _Nullable)getOrNull __attribute__((swift_name("getOrNull()")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse isLeft()")));
- (BOOL)isLeft __attribute__((swift_name("isLeft()")));
- (BOOL)isLeftPredicate:(PresenterBaseBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("isLeft(predicate:)")));
- (BOOL)isNotEmpty __attribute__((swift_name("isNotEmpty()"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse isRight()")));
- (BOOL)isRight __attribute__((swift_name("isRight()")));
- (BOOL)isRightPredicate:(PresenterBaseBoolean *(^)(B _Nullable))predicate __attribute__((swift_name("isRight(predicate:)")));
- (A _Nullable)leftOrNull __attribute__((swift_name("leftOrNull()")));
- (PresenterBaseArrow_coreEither<A, id> *)mapF:(id _Nullable (^)(B _Nullable))f __attribute__((swift_name("map(f:)")));
- (PresenterBaseArrow_coreEither<id, B> *)mapLeftF:(id _Nullable (^)(A _Nullable))f __attribute__((swift_name("mapLeft(f:)")));
- (PresenterBaseArrow_coreEither<A, B> *)onLeftAction:(void (^)(A _Nullable))action __attribute__((swift_name("onLeft(action:)")));
- (PresenterBaseArrow_coreEither<A, B> *)onRightAction:(void (^)(B _Nullable))action __attribute__((swift_name("onRight(action:)")));
- (PresenterBaseArrow_coreOption<B> *)orNone __attribute__((swift_name("orNone()"))) __attribute__((deprecated("orNone is being renamed to getOrNone to be more consistent with the Kotlin Standard Library naming")));
- (B _Nullable)orNull __attribute__((swift_name("orNull()"))) __attribute__((deprecated("orNull is being renamed to getOrNull to be more consistent with the Kotlin Standard Library naming")));
- (PresenterBaseArrow_coreEither<A, NSArray<id> *> *)replicateN:(int32_t)n __attribute__((swift_name("replicate(n:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Either DSL, or map")));
- (PresenterBaseArrow_coreEither<B, A> *)swap __attribute__((swift_name("swap()")));
- (PresenterBaseArrow_coreEither<A, B> *)tapF:(void (^)(B _Nullable))f __attribute__((swift_name("tap(f:)"))) __attribute__((deprecated("tap is being renamed to onRight to be more consistent with the Kotlin Standard Library naming")));
- (PresenterBaseArrow_coreEither<A, B> *)tapLeftF:(void (^)(A _Nullable))f __attribute__((swift_name("tapLeft(f:)"))) __attribute__((deprecated("tapLeft is being renamed to onLeft to be more consistent with the Kotlin Standard Library naming")));
- (PresenterBaseArrow_coreEither<A, B> *)toEither __attribute__((swift_name("toEither()"))) __attribute__((deprecated("Facilitates the migration from Validated to Either, you can simply remove this method call.")));
- (PresenterBaseArrow_coreIor<A, B> *)toIor __attribute__((swift_name("toIor()")));
- (NSString *)description __attribute__((swift_name("description()")));
- (PresenterBaseArrow_coreValidated<A, B> *)toValidated __attribute__((swift_name("toValidated()"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nYou can find more details about how to migrate on the Github release page, or the 1.2.0 release post.")));
- (PresenterBaseArrow_coreValidated<NSArray<id> *, B> *)toValidatedNel __attribute__((swift_name("toValidatedNel()"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nValidatedNel is being replaced by EitherNel")));
- (PresenterBaseArrow_coreOption<PresenterBaseArrow_coreEither<A, id> *> *)traverseFa:(PresenterBaseArrow_coreOption<id> *(^)(B _Nullable))fa __attribute__((swift_name("traverse(fa:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Either DSL, or explicit fold or when")));
- (PresenterBaseArrow_coreValidated<id, PresenterBaseArrow_coreEither<A, id> *> *)traverseFa_:(PresenterBaseArrow_coreValidated<id, id> *(^)(B _Nullable))fa __attribute__((swift_name("traverse(fa_:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Either DSL, or explicit fold or when")));
- (NSArray<PresenterBaseArrow_coreEither<A, id> *> *)traverseFa__:(id (^)(B _Nullable))fa __attribute__((swift_name("traverse(fa__:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Either DSL, or explicit fold or when")));
- (PresenterBaseArrow_coreEither<A, id> * _Nullable)traverseNullableFa:(id _Nullable (^)(B _Nullable))fa __attribute__((swift_name("traverseNullable(fa:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse orNull() and Kotlin nullable types")));
- (PresenterBaseArrow_coreOption<PresenterBaseArrow_coreEither<A, id> *> *)traverseOptionFa:(PresenterBaseArrow_coreOption<id> *(^)(B _Nullable))fa __attribute__((swift_name("traverseOption(fa:)"))) __attribute__((deprecated("traverseOption is being renamed to traverse to simplify the Arrow API")));
- (PresenterBaseArrow_coreValidated<id, PresenterBaseArrow_coreEither<A, id> *> *)traverseValidatedFa:(PresenterBaseArrow_coreValidated<id, id> *(^)(B _Nullable))fa __attribute__((swift_name("traverseValidated(fa:)"))) __attribute__((deprecated("traverseValidated is being renamed to traverse to simplify the Arrow API")));
- (PresenterBaseArrow_coreEither<A, PresenterBaseKotlinUnit *> *)void __attribute__((swift_name("void()"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nMap with Unit")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinUnit")))
@interface PresenterBaseKotlinUnit : PresenterBaseBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)unit __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PresenterBaseKotlinUnit *shared __attribute__((swift_name("shared")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("ModelObj")))
@interface PresenterBaseModelObj : PresenterBaseBase
- (instancetype)initWithUid:(int32_t)uid __attribute__((swift_name("init(uid:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t uid __attribute__((swift_name("uid")));
@end

__attribute__((swift_name("Arrow_coreIor")))
@interface PresenterBaseArrow_coreIor<__covariant A, __covariant B> : PresenterBaseBase
@property (class, readonly, getter=companion) PresenterBaseArrow_coreIorCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)allPredicate:(PresenterBaseBoolean *(^)(B _Nullable))predicate __attribute__((swift_name("all(predicate:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using fold, or map + getOrElse. See the Arrow web migration guide for more info.")));
- (NSArray<PresenterBaseArrow_coreIor<id, id> *> *)bicrosswalkFa:(id (^)(A _Nullable))fa fb:(id (^)(B _Nullable))fb __attribute__((swift_name("bicrosswalk(fa:fb:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (NSDictionary<id, PresenterBaseArrow_coreIor<id, id> *> *)bicrosswalkMapFa:(NSDictionary<id, id> *(^)(A _Nullable))fa fb:(NSDictionary<id, id> *(^)(B _Nullable))fb __attribute__((swift_name("bicrosswalkMap(fa:fb:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterBaseArrow_coreIor<id, id> * _Nullable)bicrosswalkNullFa:(id _Nullable (^)(A _Nullable))fa fb:(id _Nullable (^)(B _Nullable))fb __attribute__((swift_name("bicrosswalkNull(fa:fb:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (id _Nullable)bifoldLeftC:(id _Nullable)c f:(id _Nullable (^)(id _Nullable, A _Nullable))f g:(id _Nullable (^)(id _Nullable, B _Nullable))g __attribute__((swift_name("bifoldLeft(c:f:g:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (id _Nullable)bifoldMapMN:(id<PresenterBaseArrow_coreMonoid>)MN f:(id _Nullable (^)(A _Nullable))f g:(id _Nullable (^)(B _Nullable))g __attribute__((swift_name("bifoldMap(MN:f:g:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead. See the Arrow web migration guide for more info.")));
- (PresenterBaseArrow_coreIor<id, id> *)bimapFa:(id _Nullable (^)(A _Nullable))fa fb:(id _Nullable (^)(B _Nullable))fb __attribute__((swift_name("bimap(fa:fb:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Either DSL, or map + mapLeft")));
- (NSArray<PresenterBaseArrow_coreIor<id, id> *> *)bitraverseFa:(id (^)(A _Nullable))fa fb:(id (^)(B _Nullable))fb __attribute__((swift_name("bitraverse(fa:fb:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterBaseArrow_coreEither<id, PresenterBaseArrow_coreIor<id, id> *> *)bitraverseEitherFa:(PresenterBaseArrow_coreEither<id, id> *(^)(A _Nullable))fa fb:(PresenterBaseArrow_coreEither<id, id> *(^)(B _Nullable))fb __attribute__((swift_name("bitraverseEither(fa:fb:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterBaseArrow_coreIor<id, id> * _Nullable)bitraverseNullableFa:(id _Nullable (^)(A _Nullable))fa fb:(id _Nullable (^)(B _Nullable))fb __attribute__((swift_name("bitraverseNullable(fa:fb:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterBaseArrow_coreOption<PresenterBaseArrow_coreIor<id, id> *> *)bitraverseOptionFa:(PresenterBaseArrow_coreOption<id> *(^)(A _Nullable))fa fb:(PresenterBaseArrow_coreOption<id> *(^)(B _Nullable))fb __attribute__((swift_name("bitraverseOption(fa:fb:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterBaseArrow_coreValidated<id, PresenterBaseArrow_coreIor<id, id> *> *)bitraverseValidatedSA:(id<PresenterBaseArrow_coreSemigroup>)SA fa:(PresenterBaseArrow_coreValidated<id, id> *(^)(A _Nullable))fa fb:(PresenterBaseArrow_coreValidated<id, id> *(^)(B _Nullable))fb __attribute__((swift_name("bitraverseValidated(SA:fa:fb:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (NSArray<PresenterBaseArrow_coreIor<A, id> *> *)crosswalkFa:(id (^)(B _Nullable))fa __attribute__((swift_name("crosswalk(fa:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (NSDictionary<id, PresenterBaseArrow_coreIor<A, id> *> *)crosswalkMapFa:(NSDictionary<id, id> *(^)(B _Nullable))fa __attribute__((swift_name("crosswalkMap(fa:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterBaseArrow_coreIor<id, id> * _Nullable)crosswalkNullIor:(PresenterBaseArrow_coreIor<id, id> *)ior fa:(id _Nullable (^)(id _Nullable))fa __attribute__((swift_name("crosswalkNull(ior:fa:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (BOOL)existsPredicate:(PresenterBaseBoolean *(^)(B _Nullable))predicate __attribute__((swift_name("exists(predicate:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using fold, or map + getOrElse")));
- (B _Nullable)findOrNullPredicate:(PresenterBaseBoolean *(^)(B _Nullable))predicate __attribute__((swift_name("findOrNull(predicate:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer Kotlin nullable syntax instead")));
- (id _Nullable)foldFa:(id _Nullable (^)(A _Nullable))fa fb:(id _Nullable (^)(B _Nullable))fb fab:(id _Nullable (^)(A _Nullable, B _Nullable))fab __attribute__((swift_name("fold(fa:fb:fab:)")));
- (id _Nullable)foldLeftC:(id _Nullable)c f:(id _Nullable (^)(id _Nullable, B _Nullable))f __attribute__((swift_name("foldLeft(c:f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (id _Nullable)foldMapMN:(id<PresenterBaseArrow_coreMonoid>)MN f:(id _Nullable (^)(B _Nullable))f __attribute__((swift_name("foldMap(MN:f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (B _Nullable)getOrNull __attribute__((swift_name("getOrNull()")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="_isBoth")
*/
- (BOOL)isBoth __attribute__((swift_name("isBoth()")));
- (BOOL)isBothLeftPredicate:(PresenterBaseBoolean *(^)(A _Nullable))leftPredicate rightPredicate:(PresenterBaseBoolean *(^)(B _Nullable))rightPredicate __attribute__((swift_name("isBoth(leftPredicate:rightPredicate:)")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using isLeft")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="_isLeft")
*/
- (BOOL)isLeft __attribute__((swift_name("isLeft()")));
- (BOOL)isLeftPredicate:(PresenterBaseBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("isLeft(predicate:)")));
- (BOOL)isNotEmpty __attribute__((swift_name("isNotEmpty()"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using isRight and isBoth")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="_isRight")
*/
- (BOOL)isRight __attribute__((swift_name("isRight()")));
- (BOOL)isRightPredicate:(PresenterBaseBoolean *(^)(B _Nullable))predicate __attribute__((swift_name("isRight(predicate:)")));
- (A _Nullable)leftOrNull __attribute__((swift_name("leftOrNull()")));
- (PresenterBaseArrow_coreIor<A, id> *)mapF:(id _Nullable (^)(B _Nullable))f __attribute__((swift_name("map(f:)")));
- (PresenterBaseArrow_coreIor<id, B> *)mapLeftFa:(id _Nullable (^)(A _Nullable))fa __attribute__((swift_name("mapLeft(fa:)")));
- (B _Nullable)orNull __attribute__((swift_name("orNull()"))) __attribute__((deprecated("orNull is being renamed to getOrNull to be more consistent with the Kotlin Standard Library naming")));
- (PresenterBaseKotlinPair<A, B> *)padNull __attribute__((swift_name("padNull()"))) __attribute__((deprecated("padNull is being renamed to toPair to be more consistent with the Kotlin Standard Library naming")));
- (PresenterBaseArrow_coreIor<B, A> *)swap __attribute__((swift_name("swap()")));
- (PresenterBaseArrow_coreEither<A, B> *)toEither __attribute__((swift_name("toEither()")));
- (PresenterBaseKotlinPair<A, B> *)toPair __attribute__((swift_name("toPair()")));
- (NSString *)description __attribute__((swift_name("description()")));
- (PresenterBaseArrow_coreValidated<A, B> *)toValidated __attribute__((swift_name("toValidated()"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using fold. See the Arrow web migration guide for more info.")));
- (PresenterBaseArrow_coreEither<id, PresenterBaseArrow_coreIor<A, id> *> *)traverseFa:(PresenterBaseArrow_coreEither<id, id> *(^)(B _Nullable))fa __attribute__((swift_name("traverse(fa:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterBaseArrow_coreOption<PresenterBaseArrow_coreIor<A, id> *> *)traverseFa_:(PresenterBaseArrow_coreOption<id> *(^)(B _Nullable))fa __attribute__((swift_name("traverse(fa_:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterBaseArrow_coreValidated<id, PresenterBaseArrow_coreIor<A, id> *> *)traverseFa__:(PresenterBaseArrow_coreValidated<id, id> *(^)(B _Nullable))fa __attribute__((swift_name("traverse(fa__:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when")));
- (NSArray<PresenterBaseArrow_coreIor<A, id> *> *)traverseFa___:(id (^)(B _Nullable))fa __attribute__((swift_name("traverse(fa___:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterBaseArrow_coreEither<id, PresenterBaseArrow_coreIor<A, id> *> *)traverseEitherFa:(PresenterBaseArrow_coreEither<id, id> *(^)(B _Nullable))fa __attribute__((swift_name("traverseEither(fa:)"))) __attribute__((deprecated("traverseEither is being renamed to traverse to simplify the Arrow API")));
- (PresenterBaseArrow_coreIor<A, id> * _Nullable)traverseNullableFa:(id _Nullable (^)(B _Nullable))fa __attribute__((swift_name("traverseNullable(fa:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using Ior DSL, or explicit fold, or when. See the Arrow web migration guide for more info.")));
- (PresenterBaseArrow_coreOption<PresenterBaseArrow_coreIor<A, id> *> *)traverseOptionFa:(PresenterBaseArrow_coreOption<id> *(^)(B _Nullable))fa __attribute__((swift_name("traverseOption(fa:)"))) __attribute__((deprecated("traverseOption is being renamed to traverse to simplify the Arrow API")));
- (PresenterBaseArrow_coreValidated<id, PresenterBaseArrow_coreIor<A, id> *> *)traverseValidatedFa:(PresenterBaseArrow_coreValidated<id, id> *(^)(B _Nullable))fa __attribute__((swift_name("traverseValidated(fa:)"))) __attribute__((deprecated("traverseValidated is being renamed to traverse to simplify the Arrow API")));
- (PresenterBaseArrow_coreEither<PresenterBaseArrow_coreEither<A, B> *, PresenterBaseKotlinPair<A, B> *> *)unwrap __attribute__((swift_name("unwrap()")));
- (PresenterBaseArrow_coreIor<A, PresenterBaseKotlinUnit *> *)void __attribute__((swift_name("void()"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using map")));
@property (readonly, getter=isBoth_) BOOL isBoth __attribute__((swift_name("isBoth"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse isBoth()")));
@property (readonly, getter=isLeft_) BOOL isLeft __attribute__((swift_name("isLeft"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse isLeft()")));
@property (readonly, getter=isRight_) BOOL isRight __attribute__((swift_name("isRight"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse isRight()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelLevel")))
@interface PresenterBaseModelLevel : PresenterBaseKotlinEnum<PresenterBaseModelLevel *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) PresenterBaseModelLevel *debug __attribute__((swift_name("debug")));
@property (class, readonly) PresenterBaseModelLevel *alert __attribute__((swift_name("alert")));
+ (PresenterBaseKotlinArray<PresenterBaseModelLevel *> *)values __attribute__((swift_name("values()")));
@end

__attribute__((swift_name("KotlinThrowable")))
@interface PresenterBaseKotlinThrowable : PresenterBaseBase
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(PresenterBaseKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(PresenterBaseKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.experimental.ExperimentalNativeApi
*/
- (PresenterBaseKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) PresenterBaseKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
- (NSError *)asError __attribute__((swift_name("asError()")));
@end

__attribute__((swift_name("KotlinException")))
@interface PresenterBaseKotlinException : PresenterBaseKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(PresenterBaseKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(PresenterBaseKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinRuntimeException")))
@interface PresenterBaseKotlinRuntimeException : PresenterBaseKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(PresenterBaseKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(PresenterBaseKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinIllegalStateException")))
@interface PresenterBaseKotlinIllegalStateException : PresenterBaseKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(PresenterBaseKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(PresenterBaseKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
__attribute__((swift_name("KotlinCancellationException")))
@interface PresenterBaseKotlinCancellationException : PresenterBaseKotlinIllegalStateException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(PresenterBaseKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(PresenterBaseKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelIncorrectCount")))
@interface PresenterBaseModelIncorrectCount : PresenterBaseModelProviderError
- (instancetype)initWithIds:(NSArray<PresenterBaseInt *> *)ids __attribute__((swift_name("init(ids:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSArray<PresenterBaseInt *> *ids __attribute__((swift_name("ids")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelMove")))
@interface PresenterBaseModelMove : PresenterBaseModelObj
- (instancetype)initWithUid:(int32_t)uid name:(NSString *)name attributes:(NSDictionary<NSString *, NSString *> *)attributes __attribute__((swift_name("init(uid:name:attributes:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithUid:(int32_t)uid __attribute__((swift_name("init(uid:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (PresenterBaseModelMove *)doCopyUid:(int32_t)uid name:(NSString *)name attributes:(NSDictionary<NSString *, NSString *> *)attributes __attribute__((swift_name("doCopy(uid:name:attributes:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSDictionary<NSString *, NSString *> *attributes __attribute__((swift_name("attributes")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t uid __attribute__((swift_name("uid")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelCharacter")))
@interface PresenterBaseModelCharacter : PresenterBaseModelObj
- (instancetype)initWithUid:(int32_t)uid name:(NSString *)name attributes:(NSDictionary<NSString *, NSString *> *)attributes moveIds:(NSArray<PresenterBaseInt *> *)moveIds iconUrl:(NSString *)iconUrl __attribute__((swift_name("init(uid:name:attributes:moveIds:iconUrl:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithUid:(int32_t)uid __attribute__((swift_name("init(uid:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (PresenterBaseModelCharacter *)doCopyUid:(int32_t)uid name:(NSString *)name attributes:(NSDictionary<NSString *, NSString *> *)attributes moveIds:(NSArray<PresenterBaseInt *> *)moveIds iconUrl:(NSString *)iconUrl __attribute__((swift_name("doCopy(uid:name:attributes:moveIds:iconUrl:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSDictionary<NSString *, NSString *> *attributes __attribute__((swift_name("attributes")));
@property (readonly) NSString *iconUrl __attribute__((swift_name("iconUrl")));
@property (readonly) NSArray<PresenterBaseInt *> *moveIds __attribute__((swift_name("moveIds")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t uid __attribute__((swift_name("uid")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelGame")))
@interface PresenterBaseModelGame : PresenterBaseModelObj
- (instancetype)initWithUid:(int32_t)uid name:(NSString *)name charIds:(NSArray<PresenterBaseInt *> *)charIds iconUrl:(NSString *)iconUrl __attribute__((swift_name("init(uid:name:charIds:iconUrl:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithUid:(int32_t)uid __attribute__((swift_name("init(uid:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (PresenterBaseModelGame *)doCopyUid:(int32_t)uid name:(NSString *)name charIds:(NSArray<PresenterBaseInt *> *)charIds iconUrl:(NSString *)iconUrl __attribute__((swift_name("doCopy(uid:name:charIds:iconUrl:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<PresenterBaseInt *> *charIds __attribute__((swift_name("charIds")));
@property (readonly) NSString *iconUrl __attribute__((swift_name("iconUrl")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t uid __attribute__((swift_name("uid")));
@end

__attribute__((swift_name("KotlinCoroutineContextKey")))
@protocol PresenterBaseKotlinCoroutineContextKey
@required
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinContinuation")))
@protocol PresenterBaseKotlinContinuation
@required
- (void)resumeWithResult:(id _Nullable)result __attribute__((swift_name("resumeWith(result:)")));
@property (readonly) id<PresenterBaseKotlinCoroutineContext> context __attribute__((swift_name("context")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
 *   kotlin.ExperimentalStdlibApi
*/
__attribute__((swift_name("KotlinAbstractCoroutineContextKey")))
@interface PresenterBaseKotlinAbstractCoroutineContextKey<B, E> : PresenterBaseBase <PresenterBaseKotlinCoroutineContextKey>
- (instancetype)initWithBaseKey:(id<PresenterBaseKotlinCoroutineContextKey>)baseKey safeCast:(E _Nullable (^)(id<PresenterBaseKotlinCoroutineContextElement>))safeCast __attribute__((swift_name("init(baseKey:safeCast:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.ExperimentalStdlibApi
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineDispatcher.Key")))
@interface PresenterBaseKotlinx_coroutines_coreCoroutineDispatcherKey : PresenterBaseKotlinAbstractCoroutineContextKey<id<PresenterBaseKotlinContinuationInterceptor>, PresenterBaseKotlinx_coroutines_coreCoroutineDispatcher *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithBaseKey:(id<PresenterBaseKotlinCoroutineContextKey>)baseKey safeCast:(id<PresenterBaseKotlinCoroutineContextElement> _Nullable (^)(id<PresenterBaseKotlinCoroutineContextElement>))safeCast __attribute__((swift_name("init(baseKey:safeCast:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)key __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PresenterBaseKotlinx_coroutines_coreCoroutineDispatcherKey *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreRunnable")))
@protocol PresenterBaseKotlinx_coroutines_coreRunnable
@required
- (void)run __attribute__((swift_name("run()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinEnumCompanion")))
@interface PresenterBaseKotlinEnumCompanion : PresenterBaseBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PresenterBaseKotlinEnumCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface PresenterBaseKotlinArray<T> : PresenterBaseBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(PresenterBaseInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<PresenterBaseKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ModelEvent.Value")))
@interface PresenterBaseModelEventValue : PresenterBaseKotlinEnum<PresenterBaseModelEventValue *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) PresenterBaseModelEventValue *viewEntered __attribute__((swift_name("viewEntered")));
@property (class, readonly) PresenterBaseModelEventValue *viewExited __attribute__((swift_name("viewExited")));
@property (class, readonly) PresenterBaseModelEventValue *buttonPressed __attribute__((swift_name("buttonPressed")));
@property (class, readonly) PresenterBaseModelEventValue *routingRequest __attribute__((swift_name("routingRequest")));
@property (class, readonly) PresenterBaseModelEventValue *routingDenied __attribute__((swift_name("routingDenied")));
+ (PresenterBaseKotlinArray<PresenterBaseModelEventValue *> *)values __attribute__((swift_name("values()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Arrow_coreEitherCompanion")))
@interface PresenterBaseArrow_coreEitherCompanion : PresenterBaseBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PresenterBaseArrow_coreEitherCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
 *   kotlin.jvm.JvmName(name="tryCatch")
*/
- (PresenterBaseArrow_coreEither<PresenterBaseKotlinThrowable *, id> *)catchF:(id _Nullable (^)(void))f __attribute__((swift_name("catch(f:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
 *   kotlin.jvm.JvmName(name="tryCatch")
*/
- (PresenterBaseArrow_coreEither<id, id> *)catchFe:(id _Nullable (^)(PresenterBaseKotlinThrowable *))fe f:(id _Nullable (^)(void))f __attribute__((swift_name("catch(fe:f:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nCompose catch with mapLeft instead")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
 *   kotlin.jvm.JvmName(name="tryCatchAndFlatten")
*/
- (PresenterBaseArrow_coreEither<PresenterBaseKotlinThrowable *, id> *)catchAndFlattenF:(PresenterBaseArrow_coreEither<PresenterBaseKotlinThrowable *, id> *(^)(void))f __attribute__((swift_name("catchAndFlatten(f:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nCompose catch with flatten instead")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreEither<PresenterBaseKotlinThrowable *, id> *)catchOrThrowF:(id _Nullable (^)(void))f __attribute__((swift_name("catchOrThrow(f:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreEither<id, id> *)conditionallyTest:(BOOL)test ifFalse:(id _Nullable (^)(void))ifFalse ifTrue:(id _Nullable (^)(void))ifTrue __attribute__((swift_name("conditionally(test:ifFalse:ifTrue:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicit if-else statements, or ensure inside Either DSL")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreEither<PresenterBaseKotlinUnit *, id> *)fromNullableA:(id _Nullable)a __attribute__((swift_name("fromNullable(a:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer Kotlin nullable syntax, or ensureNotNull inside Either DSL")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreEither<id, id> *(^)(PresenterBaseArrow_coreEither<id, id> *))liftFa:(id _Nullable (^)(id _Nullable))fa fb:(id _Nullable (^)(id _Nullable))fb __attribute__((swift_name("lift(fa:fb:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicitly creating lambdas")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreEither<id, id> *(^)(PresenterBaseArrow_coreEither<id, id> *))liftF:(id _Nullable (^)(id _Nullable))f __attribute__((swift_name("lift(f:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicitly creating lambdas")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (id _Nullable)resolveF:(PresenterBaseArrow_coreEither<id, id> *(^)(void))f success:(PresenterBaseArrow_coreEither<PresenterBaseKotlinThrowable *, id> *(^)(id _Nullable))success error:(PresenterBaseArrow_coreEither<PresenterBaseKotlinThrowable *, id> *(^)(id _Nullable))error throwable:(PresenterBaseArrow_coreEither<PresenterBaseKotlinThrowable *, id> *(^)(PresenterBaseKotlinThrowable *))throwable unrecoverableState:(PresenterBaseArrow_coreEither<PresenterBaseKotlinThrowable *, PresenterBaseKotlinUnit *> *(^)(PresenterBaseKotlinThrowable *))unrecoverableState __attribute__((swift_name("resolve(f:success:error:throwable:unrecoverableState:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using recover, catch and the either DSL to work with errors")));
- (PresenterBaseArrow_coreEither<id, id> *)zipOrAccumulateCombine:(id _Nullable (^)(id _Nullable, id _Nullable))combine a:(PresenterBaseArrow_coreEither<id, id> *)a b:(PresenterBaseArrow_coreEither<id, id> *)b transform:(id _Nullable (^)(id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(combine:a:b:transform:)")));
- (PresenterBaseArrow_coreEither<id, id> *)zipOrAccumulateCombine:(id _Nullable (^)(id _Nullable, id _Nullable))combine a:(PresenterBaseArrow_coreEither<id, id> *)a b:(PresenterBaseArrow_coreEither<id, id> *)b c:(PresenterBaseArrow_coreEither<id, id> *)c transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(combine:a:b:c:transform:)")));
- (PresenterBaseArrow_coreEither<id, id> *)zipOrAccumulateCombine:(id _Nullable (^)(id _Nullable, id _Nullable))combine a:(PresenterBaseArrow_coreEither<id, id> *)a b:(PresenterBaseArrow_coreEither<id, id> *)b c:(PresenterBaseArrow_coreEither<id, id> *)c d:(PresenterBaseArrow_coreEither<id, id> *)d transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(combine:a:b:c:d:transform:)")));
- (PresenterBaseArrow_coreEither<id, id> *)zipOrAccumulateCombine:(id _Nullable (^)(id _Nullable, id _Nullable))combine a:(PresenterBaseArrow_coreEither<id, id> *)a b:(PresenterBaseArrow_coreEither<id, id> *)b c:(PresenterBaseArrow_coreEither<id, id> *)c d:(PresenterBaseArrow_coreEither<id, id> *)d e:(PresenterBaseArrow_coreEither<id, id> *)e transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(combine:a:b:c:d:e:transform:)")));
- (PresenterBaseArrow_coreEither<id, id> *)zipOrAccumulateCombine:(id _Nullable (^)(id _Nullable, id _Nullable))combine a:(PresenterBaseArrow_coreEither<id, id> *)a b:(PresenterBaseArrow_coreEither<id, id> *)b c:(PresenterBaseArrow_coreEither<id, id> *)c d:(PresenterBaseArrow_coreEither<id, id> *)d e:(PresenterBaseArrow_coreEither<id, id> *)e f:(PresenterBaseArrow_coreEither<id, id> *)f g:(PresenterBaseArrow_coreEither<id, id> *)g transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(combine:a:b:c:d:e:f:g:transform:)")));
- (PresenterBaseArrow_coreEither<id, id> *)zipOrAccumulateCombine:(id _Nullable (^)(id _Nullable, id _Nullable))combine a:(PresenterBaseArrow_coreEither<id, id> *)a b:(PresenterBaseArrow_coreEither<id, id> *)b c:(PresenterBaseArrow_coreEither<id, id> *)c d:(PresenterBaseArrow_coreEither<id, id> *)d e:(PresenterBaseArrow_coreEither<id, id> *)e f:(PresenterBaseArrow_coreEither<id, id> *)f g:(PresenterBaseArrow_coreEither<id, id> *)g h:(PresenterBaseArrow_coreEither<id, id> *)h transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(combine:a:b:c:d:e:f:g:h:transform:)")));
- (PresenterBaseArrow_coreEither<id, id> *)zipOrAccumulateCombine:(id _Nullable (^)(id _Nullable, id _Nullable))combine a:(PresenterBaseArrow_coreEither<id, id> *)a b:(PresenterBaseArrow_coreEither<id, id> *)b c:(PresenterBaseArrow_coreEither<id, id> *)c d:(PresenterBaseArrow_coreEither<id, id> *)d e:(PresenterBaseArrow_coreEither<id, id> *)e f:(PresenterBaseArrow_coreEither<id, id> *)f g:(PresenterBaseArrow_coreEither<id, id> *)g h:(PresenterBaseArrow_coreEither<id, id> *)h i:(PresenterBaseArrow_coreEither<id, id> *)i transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(combine:a:b:c:d:e:f:g:h:i:transform:)")));
- (PresenterBaseArrow_coreEither<id, id> *)zipOrAccumulateCombine:(id _Nullable (^)(id _Nullable, id _Nullable))combine a:(PresenterBaseArrow_coreEither<id, id> *)a b:(PresenterBaseArrow_coreEither<id, id> *)b c:(PresenterBaseArrow_coreEither<id, id> *)c d:(PresenterBaseArrow_coreEither<id, id> *)d e:(PresenterBaseArrow_coreEither<id, id> *)e f:(PresenterBaseArrow_coreEither<id, id> *)f g:(PresenterBaseArrow_coreEither<id, id> *)g h:(PresenterBaseArrow_coreEither<id, id> *)h i:(PresenterBaseArrow_coreEither<id, id> *)i j:(PresenterBaseArrow_coreEither<id, id> *)j transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(combine:a:b:c:d:e:f:g:h:i:j:transform:)")));
- (PresenterBaseArrow_coreEither<id, id> *)zipOrAccumulateCombine:(id _Nullable (^)(id _Nullable, id _Nullable))combine a:(PresenterBaseArrow_coreEither<id, id> *)a b:(PresenterBaseArrow_coreEither<id, id> *)b c:(PresenterBaseArrow_coreEither<id, id> *)c d:(PresenterBaseArrow_coreEither<id, id> *)d e:(PresenterBaseArrow_coreEither<id, id> *)e f:(PresenterBaseArrow_coreEither<id, id> *)f transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(combine:a:b:c:d:e:f:transform:)")));
- (PresenterBaseArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterBaseArrow_coreEither<id, id> *)a b:(PresenterBaseArrow_coreEither<id, id> *)b transform:(id _Nullable (^)(id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:transform:)")));
- (PresenterBaseArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterBaseArrow_coreEither<id, id> *)a b:(PresenterBaseArrow_coreEither<id, id> *)b c:(PresenterBaseArrow_coreEither<id, id> *)c transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:transform:)")));
- (PresenterBaseArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterBaseArrow_coreEither<id, id> *)a b:(PresenterBaseArrow_coreEither<id, id> *)b c:(PresenterBaseArrow_coreEither<id, id> *)c d:(PresenterBaseArrow_coreEither<id, id> *)d transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:transform:)")));
- (PresenterBaseArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterBaseArrow_coreEither<id, id> *)a b:(PresenterBaseArrow_coreEither<id, id> *)b c:(PresenterBaseArrow_coreEither<id, id> *)c d:(PresenterBaseArrow_coreEither<id, id> *)d e:(PresenterBaseArrow_coreEither<id, id> *)e transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:transform:)")));
- (PresenterBaseArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterBaseArrow_coreEither<id, id> *)a b:(PresenterBaseArrow_coreEither<id, id> *)b c:(PresenterBaseArrow_coreEither<id, id> *)c d:(PresenterBaseArrow_coreEither<id, id> *)d e:(PresenterBaseArrow_coreEither<id, id> *)e f:(PresenterBaseArrow_coreEither<id, id> *)f g:(PresenterBaseArrow_coreEither<id, id> *)g transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:g:transform:)")));
- (PresenterBaseArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterBaseArrow_coreEither<id, id> *)a b:(PresenterBaseArrow_coreEither<id, id> *)b c:(PresenterBaseArrow_coreEither<id, id> *)c d:(PresenterBaseArrow_coreEither<id, id> *)d e:(PresenterBaseArrow_coreEither<id, id> *)e f:(PresenterBaseArrow_coreEither<id, id> *)f g:(PresenterBaseArrow_coreEither<id, id> *)g h:(PresenterBaseArrow_coreEither<id, id> *)h transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:g:h:transform:)")));
- (PresenterBaseArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterBaseArrow_coreEither<id, id> *)a b:(PresenterBaseArrow_coreEither<id, id> *)b c:(PresenterBaseArrow_coreEither<id, id> *)c d:(PresenterBaseArrow_coreEither<id, id> *)d e:(PresenterBaseArrow_coreEither<id, id> *)e f:(PresenterBaseArrow_coreEither<id, id> *)f g:(PresenterBaseArrow_coreEither<id, id> *)g h:(PresenterBaseArrow_coreEither<id, id> *)h i:(PresenterBaseArrow_coreEither<id, id> *)i transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:g:h:i:transform:)")));
- (PresenterBaseArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterBaseArrow_coreEither<id, id> *)a b:(PresenterBaseArrow_coreEither<id, id> *)b c:(PresenterBaseArrow_coreEither<id, id> *)c d:(PresenterBaseArrow_coreEither<id, id> *)d e:(PresenterBaseArrow_coreEither<id, id> *)e f:(PresenterBaseArrow_coreEither<id, id> *)f g:(PresenterBaseArrow_coreEither<id, id> *)g h:(PresenterBaseArrow_coreEither<id, id> *)h i:(PresenterBaseArrow_coreEither<id, id> *)i j:(PresenterBaseArrow_coreEither<id, id> *)j transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:g:h:i:j:transform:)")));
- (PresenterBaseArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterBaseArrow_coreEither<id, id> *)a b:(PresenterBaseArrow_coreEither<id, id> *)b c:(PresenterBaseArrow_coreEither<id, id> *)c d:(PresenterBaseArrow_coreEither<id, id> *)d e:(PresenterBaseArrow_coreEither<id, id> *)e f:(PresenterBaseArrow_coreEither<id, id> *)f transform:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:transform:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="zipOrAccumulateNonEmptyList")
*/
- (PresenterBaseArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)a b:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)b transform_:(id _Nullable (^)(id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:transform_:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="zipOrAccumulateNonEmptyList")
*/
- (PresenterBaseArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)a b:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)b c:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)c transform_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:transform_:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="zipOrAccumulateNonEmptyList")
*/
- (PresenterBaseArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)a b:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)b c:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)c d:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)d transform_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:transform_:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="zipOrAccumulateNonEmptyList")
*/
- (PresenterBaseArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)a b:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)b c:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)c d:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)d e:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)e transform_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:transform_:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="zipOrAccumulateNonEmptyList")
*/
- (PresenterBaseArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)a b:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)b c:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)c d:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)d e:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)e f:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)f g:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)g transform_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:g:transform_:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="zipOrAccumulateNonEmptyList")
*/
- (PresenterBaseArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)a b:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)b c:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)c d:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)d e:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)e f:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)f g:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)g h:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)h transform_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:g:h:transform_:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="zipOrAccumulateNonEmptyList")
*/
- (PresenterBaseArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)a b:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)b c:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)c d:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)d e:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)e f:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)f g:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)g h:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)h i:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)i transform_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:g:h:i:transform_:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="zipOrAccumulateNonEmptyList")
*/
- (PresenterBaseArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)a b:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)b c:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)c d:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)d e:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)e f:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)f g:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)g h:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)h i:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)i j:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)j transform_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:g:h:i:j:transform_:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="zipOrAccumulateNonEmptyList")
*/
- (PresenterBaseArrow_coreEither<NSArray<id> *, id> *)zipOrAccumulateA:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)a b:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)b c:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)c d:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)d e:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)e f:(PresenterBaseArrow_coreEither<NSArray<id> *, id> *)f transform_:(id _Nullable (^)(id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))transform __attribute__((swift_name("zipOrAccumulate(a:b:c:d:e:f:transform_:)")));
@end

__attribute__((swift_name("Arrow_coreSemigroup")))
@protocol PresenterBaseArrow_coreSemigroup
@required
- (id _Nullable)appendA:(id _Nullable)a b:(id _Nullable)b __attribute__((swift_name("append(a:b:)")));
- (id _Nullable)combine:(id _Nullable)receiver b:(id _Nullable)b __attribute__((swift_name("combine(_:b:)")));
- (id _Nullable)maybeCombine:(id _Nullable)receiver b:(id _Nullable)b __attribute__((swift_name("maybeCombine(_:b:)")));
- (id _Nullable)plus:(id _Nullable)receiver b:(id _Nullable)b __attribute__((swift_name("plus(_:b:)")));
@end

__attribute__((swift_name("Arrow_coreMonoid")))
@protocol PresenterBaseArrow_coreMonoid <PresenterBaseArrow_coreSemigroup>
@required
- (id _Nullable)combineAllElems:(NSArray<id> *)elems __attribute__((swift_name("combineAll(elems:)"))) __attribute__((deprecated("use fold instead")));
- (id _Nullable)empty __attribute__((swift_name("empty()")));
- (id _Nullable)foldElems:(NSArray<id> *)elems __attribute__((swift_name("fold(elems:)")));
- (id _Nullable)combineAll:(id)receiver __attribute__((swift_name("combineAll(_:)"))) __attribute__((deprecated("use fold instead")));
- (id _Nullable)fold:(id)receiver __attribute__((swift_name("fold(_:)")));
@end

__attribute__((swift_name("Arrow_coreOption")))
@interface PresenterBaseArrow_coreOption<__covariant A> : PresenterBaseBase
@property (class, readonly, getter=companion) PresenterBaseArrow_coreOptionCompanion *companion __attribute__((swift_name("companion")));
- (PresenterBaseArrow_coreOption<PresenterBaseArrow_coreIor<A, id> *> *)alignB:(PresenterBaseArrow_coreOption<id> *)b __attribute__((swift_name("align(b:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using a simple fold, or when expression")));
- (PresenterBaseArrow_coreOption<id> *)alignB:(PresenterBaseArrow_coreOption<id> *)b f:(id _Nullable (^)(PresenterBaseArrow_coreIor<A, id> *))f __attribute__((swift_name("align(b:f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using a simple fold, or when expression")));
- (BOOL)allPredicate:(PresenterBaseBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("all(predicate:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL, or fold or map")));
- (PresenterBaseArrow_coreOption<id> *)andValue:(PresenterBaseArrow_coreOption<id> *)value __attribute__((swift_name("and(value:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL or flatMap")));
- (PresenterBaseArrow_coreOption<PresenterBaseArrow_coreOption<id> *> *)crosswalkF:(PresenterBaseArrow_coreOption<id> *(^)(A _Nullable))f __attribute__((swift_name("crosswalk(f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL or fold")));
- (NSDictionary<id, PresenterBaseArrow_coreOption<id> *> *)crosswalkMapF:(NSDictionary<id, id> *(^)(A _Nullable))f __attribute__((swift_name("crosswalkMap(f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL or fold")));
- (PresenterBaseArrow_coreOption<id> * _Nullable)crosswalkNullF:(id _Nullable (^)(A _Nullable))f __attribute__((swift_name("crosswalkNull(f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL or fold")));
- (BOOL)existsPredicate:(PresenterBaseBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("exists(predicate:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPlease use Option's member function isSome. This will be removed towards Arrow 2.0")));
- (PresenterBaseArrow_coreOption<A> *)filterPredicate:(PresenterBaseBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("filter(predicate:)")));
- (PresenterBaseArrow_coreOption<A> *)filterNotPredicate:(PresenterBaseBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("filterNot(predicate:)")));
- (A _Nullable)findOrNullPredicate:(PresenterBaseBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("findOrNull(predicate:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer Kotlin nullable syntax instead")));
- (PresenterBaseArrow_coreOption<id> *)flatMapF:(PresenterBaseArrow_coreOption<id> *(^)(A _Nullable))f __attribute__((swift_name("flatMap(f:)")));
- (id _Nullable)foldIfEmpty:(id _Nullable (^)(void))ifEmpty ifSome:(id _Nullable (^)(A _Nullable))ifSome __attribute__((swift_name("fold(ifEmpty:ifSome:)")));
- (id _Nullable)foldLeftInitial:(id _Nullable)initial operation:(id _Nullable (^)(id _Nullable, A _Nullable))operation __attribute__((swift_name("foldLeft(initial:operation:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (id _Nullable)foldMapMB:(id<PresenterBaseArrow_coreMonoid>)MB f:(id _Nullable (^)(A _Nullable))f __attribute__((swift_name("foldMap(MB:f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (A _Nullable)getOrNull __attribute__((swift_name("getOrNull()")));
- (BOOL)isDefined __attribute__((swift_name("isDefined()"))) __attribute__((deprecated("Duplicated API. Please use Option's member function isSome. This will be removed towards Arrow 2.0")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()"))) __attribute__((deprecated("Duplicated API. Please use Option's member function isNone. This will be removed towards Arrow 2.0")));
- (BOOL)isNone __attribute__((swift_name("isNone()")));
- (BOOL)isNotEmpty __attribute__((swift_name("isNotEmpty()"))) __attribute__((deprecated("Duplicated API. Please use Option's member function isSome. This will be removed towards Arrow 2.0")));
- (BOOL)isSome __attribute__((swift_name("isSome()")));
- (BOOL)isSomePredicate:(PresenterBaseBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("isSome(predicate:)")));
- (PresenterBaseArrow_coreOption<id> *)mapF:(id _Nullable (^)(A _Nullable))f __attribute__((swift_name("map(f:)")));
- (PresenterBaseArrow_coreOption<id> *)mapNotNullF:(id _Nullable (^)(A _Nullable))f __attribute__((swift_name("mapNotNull(f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL, or fold or map")));
- (BOOL)nonEmpty __attribute__((swift_name("nonEmpty()"))) __attribute__((deprecated("Duplicated API. Please use Option's member function isSome. This will be removed towards Arrow 2.0")));
- (PresenterBaseArrow_coreOption<A> *)onNoneAction:(void (^)(void))action __attribute__((swift_name("onNone(action:)")));
- (PresenterBaseArrow_coreOption<A> *)onSomeAction:(void (^)(A _Nullable))action __attribute__((swift_name("onSome(action:)")));
- (A _Nullable)orNull __attribute__((swift_name("orNull()"))) __attribute__((deprecated("orNull is being renamed to getOrNull to be more consistent with the Kotlin Standard Library naming")));
- (PresenterBaseArrow_coreOption<PresenterBaseKotlinPair<A, id> *> *)padZipOther:(PresenterBaseArrow_coreOption<id> *)other __attribute__((swift_name("padZip(other:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using a simple fold, or when expression")));
- (PresenterBaseArrow_coreOption<id> *)padZipOther:(PresenterBaseArrow_coreOption<id> *)other f:(id _Nullable (^)(A _Nullable, id _Nullable))f __attribute__((swift_name("padZip(other:f:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using a simple fold, or when expression")));
- (PresenterBaseArrow_coreOption<PresenterBaseKotlinPair<id, A> *> *)pairLeftLeft:(id _Nullable)left __attribute__((swift_name("pairLeft(left:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL or map")));
- (PresenterBaseArrow_coreOption<PresenterBaseKotlinPair<A, id> *> *)pairRightRight:(id _Nullable)right __attribute__((swift_name("pairRight(right:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL or map")));
- (id _Nullable)reduceOrNullInitial:(id _Nullable (^)(A _Nullable))initial operation:(id _Nullable (^)(id _Nullable, A _Nullable))operation __attribute__((swift_name("reduceOrNull(initial:operation:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (PresenterBaseArrow_coreEval<id> *)reduceRightEvalOrNullInitial:(id _Nullable (^)(A _Nullable))initial operation:(PresenterBaseArrow_coreEval<id> *(^)(A _Nullable, PresenterBaseArrow_coreEval<id> *))operation __attribute__((swift_name("reduceRightEvalOrNull(initial:operation:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (PresenterBaseArrow_coreOption<NSArray<id> *> *)replicateN:(int32_t)n __attribute__((swift_name("replicate(n:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL or map")));
- (PresenterBaseArrow_coreOption<A> *)tapF:(void (^)(A _Nullable))f __attribute__((swift_name("tap(f:)"))) __attribute__((deprecated("tap is being renamed to onNone to be more consistent with the Kotlin Standard Library naming")));
- (PresenterBaseArrow_coreOption<A> *)tapNoneF:(void (^)(void))f __attribute__((swift_name("tapNone(f:)"))) __attribute__((deprecated("tapNone is being renamed to onNone to be more consistent with the Kotlin Standard Library naming")));
- (PresenterBaseArrow_coreEither<id, A> *)toEitherIfEmpty:(id _Nullable (^)(void))ifEmpty __attribute__((swift_name("toEither(ifEmpty:)")));
- (NSArray<id> *)toList __attribute__((swift_name("toList()")));
- (NSString *)description __attribute__((swift_name("description()")));
- (PresenterBaseArrow_coreEither<id, PresenterBaseArrow_coreOption<id> *> *)traverseFa:(PresenterBaseArrow_coreEither<id, id> *(^)(A _Nullable))fa __attribute__((swift_name("traverse(fa:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL, or explicit fold or when")));
- (PresenterBaseArrow_coreValidated<id, PresenterBaseArrow_coreOption<id> *> *)traverseFa_:(PresenterBaseArrow_coreValidated<id, id> *(^)(A _Nullable))fa __attribute__((swift_name("traverse(fa_:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL, or explicit fold or when")));
- (NSArray<PresenterBaseArrow_coreOption<id> *> *)traverseFa__:(id (^)(A _Nullable))fa __attribute__((swift_name("traverse(fa__:)"))) __attribute__((deprecated("This API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Option DSL, or explicit fold or when")));
- (PresenterBaseArrow_coreEither<id, PresenterBaseArrow_coreOption<id> *> *)traverseEitherFa:(PresenterBaseArrow_coreEither<id, id> *(^)(A _Nullable))fa __attribute__((swift_name("traverseEither(fa:)"))) __attribute__((deprecated("traverseEither is being renamed to traverse to simplify the Arrow API")));
- (PresenterBaseArrow_coreValidated<id, PresenterBaseArrow_coreOption<id> *> *)traverseValidatedFa:(PresenterBaseArrow_coreValidated<id, id> *(^)(A _Nullable))fa __attribute__((swift_name("traverseValidated(fa:)"))) __attribute__((deprecated("traverseValidated is being renamed to traverse to simplify the Arrow API")));
- (PresenterBaseArrow_coreOption<PresenterBaseKotlinUnit *> *)void __attribute__((swift_name("void()"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nReplace with map with Unit")));
- (PresenterBaseArrow_coreOption<PresenterBaseKotlinPair<A, id> *> *)zipOther:(PresenterBaseArrow_coreOption<id> *)other __attribute__((swift_name("zip(other:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
- (PresenterBaseArrow_coreOption<id> *)zipB:(PresenterBaseArrow_coreOption<id> *)b map:(id _Nullable (^)(A _Nullable, id _Nullable))map __attribute__((swift_name("zip(b:map:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
- (PresenterBaseArrow_coreOption<id> *)zipB:(PresenterBaseArrow_coreOption<id> *)b c:(PresenterBaseArrow_coreOption<id> *)c map:(id _Nullable (^)(A _Nullable, id _Nullable, id _Nullable))map __attribute__((swift_name("zip(b:c:map:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
- (PresenterBaseArrow_coreOption<id> *)zipB:(PresenterBaseArrow_coreOption<id> *)b c:(PresenterBaseArrow_coreOption<id> *)c d:(PresenterBaseArrow_coreOption<id> *)d map:(id _Nullable (^)(A _Nullable, id _Nullable, id _Nullable, id _Nullable))map __attribute__((swift_name("zip(b:c:d:map:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
- (PresenterBaseArrow_coreOption<id> *)zipB:(PresenterBaseArrow_coreOption<id> *)b c:(PresenterBaseArrow_coreOption<id> *)c d:(PresenterBaseArrow_coreOption<id> *)d e:(PresenterBaseArrow_coreOption<id> *)e map:(id _Nullable (^)(A _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))map __attribute__((swift_name("zip(b:c:d:e:map:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
- (PresenterBaseArrow_coreOption<id> *)zipB:(PresenterBaseArrow_coreOption<id> *)b c:(PresenterBaseArrow_coreOption<id> *)c d:(PresenterBaseArrow_coreOption<id> *)d e:(PresenterBaseArrow_coreOption<id> *)e f:(PresenterBaseArrow_coreOption<id> *)f map:(id _Nullable (^)(A _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))map __attribute__((swift_name("zip(b:c:d:e:f:map:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
- (PresenterBaseArrow_coreOption<id> *)zipB:(PresenterBaseArrow_coreOption<id> *)b c:(PresenterBaseArrow_coreOption<id> *)c d:(PresenterBaseArrow_coreOption<id> *)d e:(PresenterBaseArrow_coreOption<id> *)e f:(PresenterBaseArrow_coreOption<id> *)f g:(PresenterBaseArrow_coreOption<id> *)g map:(id _Nullable (^)(A _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))map __attribute__((swift_name("zip(b:c:d:e:f:g:map:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
- (PresenterBaseArrow_coreOption<id> *)zipB:(PresenterBaseArrow_coreOption<id> *)b c:(PresenterBaseArrow_coreOption<id> *)c d:(PresenterBaseArrow_coreOption<id> *)d e:(PresenterBaseArrow_coreOption<id> *)e f:(PresenterBaseArrow_coreOption<id> *)f g:(PresenterBaseArrow_coreOption<id> *)g h:(PresenterBaseArrow_coreOption<id> *)h map:(id _Nullable (^)(A _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))map __attribute__((swift_name("zip(b:c:d:e:f:g:h:map:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
- (PresenterBaseArrow_coreOption<id> *)zipB:(PresenterBaseArrow_coreOption<id> *)b c:(PresenterBaseArrow_coreOption<id> *)c d:(PresenterBaseArrow_coreOption<id> *)d e:(PresenterBaseArrow_coreOption<id> *)e f:(PresenterBaseArrow_coreOption<id> *)f g:(PresenterBaseArrow_coreOption<id> *)g h:(PresenterBaseArrow_coreOption<id> *)h i:(PresenterBaseArrow_coreOption<id> *)i map:(id _Nullable (^)(A _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))map __attribute__((swift_name("zip(b:c:d:e:f:g:h:i:map:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
- (PresenterBaseArrow_coreOption<id> *)zipB:(PresenterBaseArrow_coreOption<id> *)b c:(PresenterBaseArrow_coreOption<id> *)c d:(PresenterBaseArrow_coreOption<id> *)d e:(PresenterBaseArrow_coreOption<id> *)e f:(PresenterBaseArrow_coreOption<id> *)f g:(PresenterBaseArrow_coreOption<id> *)g h:(PresenterBaseArrow_coreOption<id> *)h i:(PresenterBaseArrow_coreOption<id> *)i j:(PresenterBaseArrow_coreOption<id> *)j map:(id _Nullable (^)(A _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable, id _Nullable))map __attribute__((swift_name("zip(b:c:d:e:f:g:h:i:j:map:)"))) __attribute__((deprecated("Prefer using the inline option DSL")));
@end

__attribute__((swift_name("Arrow_coreValidated")))
@interface PresenterBaseArrow_coreValidated<__covariant E, __covariant A> : PresenterBaseBase
@property (class, readonly, getter=companion) PresenterBaseArrow_coreValidatedCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)allPredicate:(PresenterBaseBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("all(predicate:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse fold on Either after refactoring")));
- (id _Nullable)bifoldLeftC:(id _Nullable)c fe:(id _Nullable (^)(id _Nullable, E _Nullable))fe fa:(id _Nullable (^)(id _Nullable, A _Nullable))fa __attribute__((swift_name("bifoldLeft(c:fe:fa:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (id _Nullable)bifoldMapMN:(id<PresenterBaseArrow_coreMonoid>)MN g:(id _Nullable (^)(E _Nullable))g f:(id _Nullable (^)(A _Nullable))f __attribute__((swift_name("bifoldMap(MN:g:f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer when or fold instead")));
- (PresenterBaseArrow_coreValidated<id, id> *)bimapFe:(id _Nullable (^)(E _Nullable))fe fa:(id _Nullable (^)(A _Nullable))fa __attribute__((swift_name("bimap(fe:fa:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse map and mapLeft on Either after refactoring")));
- (NSArray<PresenterBaseArrow_coreValidated<id, id> *> *)bitraverseFe:(id (^)(E _Nullable))fe fa:(id (^)(A _Nullable))fa __attribute__((swift_name("bitraverse(fe:fa:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicit fold instead")));
- (PresenterBaseArrow_coreEither<id, PresenterBaseArrow_coreValidated<id, id> *> *)bitraverseEitherFe:(PresenterBaseArrow_coreEither<id, id> *(^)(E _Nullable))fe fa:(PresenterBaseArrow_coreEither<id, id> *(^)(A _Nullable))fa __attribute__((swift_name("bitraverseEither(fe:fa:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicit fold instead")));
- (PresenterBaseArrow_coreValidated<id, id> * _Nullable)bitraverseNullableFe:(id _Nullable (^)(E _Nullable))fe fa:(id _Nullable (^)(A _Nullable))fa __attribute__((swift_name("bitraverseNullable(fe:fa:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicit fold instead")));
- (PresenterBaseArrow_coreOption<PresenterBaseArrow_coreValidated<id, id> *> *)bitraverseOptionFe:(PresenterBaseArrow_coreOption<id> *(^)(E _Nullable))fe fa:(PresenterBaseArrow_coreOption<id> *(^)(A _Nullable))fa __attribute__((swift_name("bitraverseOption(fe:fa:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicit fold instead")));
- (BOOL)existPredicate:(PresenterBaseBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("exist(predicate:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse isRight on Either after refactoring")));
- (A _Nullable)findOrNullPredicate:(PresenterBaseBoolean *(^)(A _Nullable))predicate __attribute__((swift_name("findOrNull(predicate:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse getOrNull and takeIf on Either after refactoring")));
- (id _Nullable)foldFe:(id _Nullable (^)(E _Nullable))fe fa:(id _Nullable (^)(A _Nullable))fa __attribute__((swift_name("fold(fe:fa:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse fold on Either after refactoring")));
- (id _Nullable)foldLeftB:(id _Nullable)b f:(id _Nullable (^)(id _Nullable, A _Nullable))f __attribute__((swift_name("foldLeft(b:f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse fold on Either after refactoring")));
- (id _Nullable)foldMapMB:(id<PresenterBaseArrow_coreMonoid>)MB f:(id _Nullable (^)(A _Nullable))f __attribute__((swift_name("foldMap(MB:f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse fold on Either after refactoring instead")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse isRight on Either after refactoring")));
- (BOOL)isNotEmpty __attribute__((swift_name("isNotEmpty()"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse isRight on Either after refactoring")));
- (PresenterBaseArrow_coreValidated<E, id> *)mapF:(id _Nullable (^)(A _Nullable))f __attribute__((swift_name("map(f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse map on Either after refactoring")));
- (PresenterBaseArrow_coreValidated<id, A> *)mapLeftF:(id _Nullable (^)(E _Nullable))f __attribute__((swift_name("mapLeft(f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse mapLeft on Either after refactoring")));
- (PresenterBaseArrow_coreValidated<A, E> *)swap __attribute__((swift_name("swap()"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse swap on Either after refactoring")));
- (PresenterBaseArrow_coreValidated<E, A> *)tapF:(void (^)(A _Nullable))f __attribute__((swift_name("tap(f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse onRight on Either after refactoring")));
- (PresenterBaseArrow_coreValidated<E, A> *)tapInvalidF:(void (^)(E _Nullable))f __attribute__((swift_name("tapInvalid(f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse onLeft on Either after refactoring")));
- (PresenterBaseArrow_coreEither<E, A> *)toEither __attribute__((swift_name("toEither()"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nDrop this call after refactoring")));
- (NSArray<id> *)toList __attribute__((swift_name("toList()"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse fold instead")));
- (PresenterBaseArrow_coreOption<A> *)toOption __attribute__((swift_name("toOption()"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse getOrNone on Either after refactoring")));
- (NSString *)description __attribute__((swift_name("description()")));
- (PresenterBaseArrow_coreValidated<NSArray<id> *, A> *)toValidatedNel __attribute__((swift_name("toValidatedNel()"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse toEitherNel directly instead")));
- (PresenterBaseArrow_coreEither<id, PresenterBaseArrow_coreValidated<E, id> *> *)traverseFa:(PresenterBaseArrow_coreEither<id, id> *(^)(A _Nullable))fa __attribute__((swift_name("traverse(fa:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Either DSL, or explicit fold or when")));
- (PresenterBaseArrow_coreOption<PresenterBaseArrow_coreValidated<E, id> *> *)traverseFa_:(PresenterBaseArrow_coreOption<id> *(^)(A _Nullable))fa __attribute__((swift_name("traverse(fa_:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Either DSL, or explicit fold or when")));
- (NSArray<PresenterBaseArrow_coreValidated<E, id> *> *)traverseFa__:(id (^)(A _Nullable))fa __attribute__((swift_name("traverse(fa__:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using the Either DSL, or explicit fold or when")));
- (PresenterBaseArrow_coreEither<id, PresenterBaseArrow_coreValidated<E, id> *> *)traverseEitherFa:(PresenterBaseArrow_coreEither<id, id> *(^)(A _Nullable))fa __attribute__((swift_name("traverseEither(fa:)"))) __attribute__((deprecated("traverseEither is being renamed to traverse to simplify the Arrow API")));
- (PresenterBaseArrow_coreValidated<E, id> * _Nullable)traverseNullableFa:(id _Nullable (^)(A _Nullable))fa __attribute__((swift_name("traverseNullable(fa:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse orNull() and Kotlin nullable types")));
- (PresenterBaseArrow_coreOption<PresenterBaseArrow_coreValidated<E, id> *> *)traverseOptionFa:(PresenterBaseArrow_coreOption<id> *(^)(A _Nullable))fa __attribute__((swift_name("traverseOption(fa:)"))) __attribute__((deprecated("traverseOption is being renamed to traverse to simplify the Arrow API")));
- (PresenterBaseArrow_coreValidated<E, PresenterBaseKotlinUnit *> *)void __attribute__((swift_name("void()"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse map on Either after refactoring instead")));
- (PresenterBaseArrow_coreValidated<id, id> *)withEitherF:(PresenterBaseArrow_coreEither<id, id> *(^)(PresenterBaseArrow_coreEither<E, A> *))f __attribute__((swift_name("withEither(f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse Either directly instead")));
@property (readonly) BOOL isInvalid __attribute__((swift_name("isInvalid"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse isLeft on Either after refactoring")));
@property (readonly) BOOL isValid __attribute__((swift_name("isValid"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse isRight on Either after refactoring")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Arrow_coreIorCompanion")))
@interface PresenterBaseArrow_coreIorCompanion : PresenterBaseBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PresenterBaseArrow_coreIorCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreIor<NSArray<id> *, id> *)bothNelA:(id _Nullable)a b:(id _Nullable)b __attribute__((swift_name("bothNel(a:b:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreIor<id, id> * _Nullable)fromNullablesA:(id _Nullable)a b:(id _Nullable)b __attribute__((swift_name("fromNullables(a:b:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreIor<NSArray<id> *, id> *)leftNelA:(id _Nullable)a __attribute__((swift_name("leftNel(a:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreIor<id, id> *(^)(PresenterBaseArrow_coreIor<id, id> *))liftFa:(id _Nullable (^)(id _Nullable))fa fb:(id _Nullable (^)(id _Nullable))fb __attribute__((swift_name("lift(fa:fb:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicitly creating lambdas")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreIor<id, id> *(^)(PresenterBaseArrow_coreIor<id, id> *))liftF:(id _Nullable (^)(id _Nullable))f __attribute__((swift_name("lift(f:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicitly creating lambdas")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinPair")))
@interface PresenterBaseKotlinPair<__covariant A, __covariant B> : PresenterBaseBase
- (instancetype)initWithFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("init(first:second:)"))) __attribute__((objc_designated_initializer));
- (PresenterBaseKotlinPair<A, B> *)doCopyFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("doCopy(first:second:)")));
- (BOOL)equalsOther:(id _Nullable)other __attribute__((swift_name("equals(other:)")));
- (int32_t)hashCode __attribute__((swift_name("hashCode()")));
- (NSString *)toString __attribute__((swift_name("toString()")));
@property (readonly) A _Nullable first __attribute__((swift_name("first")));
@property (readonly) B _Nullable second __attribute__((swift_name("second")));
@end

__attribute__((swift_name("KotlinIterator")))
@protocol PresenterBaseKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Arrow_coreOptionCompanion")))
@interface PresenterBaseArrow_coreOptionCompanion : PresenterBaseBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PresenterBaseArrow_coreOptionCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
 *   kotlin.jvm.JvmName(name="tryCatchOrNone")
*/
- (PresenterBaseArrow_coreOption<id> *)catchF:(id _Nullable (^)(void))f __attribute__((swift_name("catch(f:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
 *   kotlin.jvm.JvmName(name="tryCatch")
*/
- (PresenterBaseArrow_coreOption<id> *)catchRecover:(PresenterBaseArrow_coreOption<id> *(^)(PresenterBaseKotlinThrowable *))recover f:(id _Nullable (^)(void))f __attribute__((swift_name("catch(recover:f:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreOption<id> *)fromNullableA:(id _Nullable)a __attribute__((swift_name("fromNullable(a:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreOption<id> *)invokeA:(id _Nullable)a __attribute__((swift_name("invoke(a:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreOption<id> *(^)(PresenterBaseArrow_coreOption<id> *))liftF:(id _Nullable (^)(id _Nullable))f __attribute__((swift_name("lift(f:)"))) __attribute__((deprecated("This API is considered redundant. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer explicitly creating lambdas")));
@end

__attribute__((swift_name("Arrow_coreEval")))
@interface PresenterBaseArrow_coreEval<__covariant A> : PresenterBaseBase
@property (class, readonly, getter=companion) PresenterBaseArrow_coreEvalCompanion *companion __attribute__((swift_name("companion")));
- (PresenterBaseArrow_coreEval<id> *)coflatMapF:(id _Nullable (^)(PresenterBaseArrow_coreEval<A> *))f __attribute__((swift_name("coflatMap(f:)")));
- (PresenterBaseArrow_coreEval<id> *)flatMapF:(PresenterBaseArrow_coreEval<id> *(^)(A _Nullable))f __attribute__((swift_name("flatMap(f:)")));
- (PresenterBaseArrow_coreEval<id> *)mapF:(id _Nullable (^)(A _Nullable))f __attribute__((swift_name("map(f:)")));
- (PresenterBaseArrow_coreEval<A> *)memoize __attribute__((swift_name("memoize()")));
- (NSString *)description __attribute__((swift_name("description()")));
- (A _Nullable)value __attribute__((swift_name("value()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Arrow_coreValidatedCompanion")))
@interface PresenterBaseArrow_coreValidatedCompanion : PresenterBaseBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PresenterBaseArrow_coreValidatedCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
 *   kotlin.jvm.JvmName(name="tryCatch")
*/
- (PresenterBaseArrow_coreValidated<PresenterBaseKotlinThrowable *, id> *)catchF:(id _Nullable (^)(void))f __attribute__((swift_name("catch(f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse Either.catch instead")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
 *   kotlin.jvm.JvmName(name="tryCatch")
*/
- (PresenterBaseArrow_coreValidated<id, id> *)catchRecover:(id _Nullable (^)(PresenterBaseKotlinThrowable *))recover f:(id _Nullable (^)(void))f __attribute__((swift_name("catch(recover:f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse Either.catch and mapLeft instead")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreValidated<NSArray<PresenterBaseKotlinThrowable *> *, id> *)catchNelF:(id _Nullable (^)(void))f __attribute__((swift_name("catchNel(f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nUse Either.catch and toEitherNel instead")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreValidated<id, id> *)fromEitherE:(PresenterBaseArrow_coreEither<id, id> *)e __attribute__((swift_name("fromEither(e:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\n")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreValidated<id, id> *)fromNullableValue:(id _Nullable)value ifNull:(id _Nullable (^)(void))ifNull __attribute__((swift_name("fromNullable(value:ifNull:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer Kotlin nullable syntax, or ensureNotNull inside Either DSL")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreValidated<id, id> *)fromOptionO:(PresenterBaseArrow_coreOption<id> *)o ifNone:(id _Nullable (^)(void))ifNone __attribute__((swift_name("fromOption(o:ifNone:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer using toEither on Option instead")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreValidated<NSArray<id> *, id> *)invalidNelE:(id _Nullable)e __attribute__((swift_name("invalidNel(e:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse leftNel instead to construct the equivalent Either value")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreValidated<id, id> *(^)(PresenterBaseArrow_coreValidated<id, id> *))liftF:(id _Nullable (^)(id _Nullable))f __attribute__((swift_name("lift(f:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer creating explicit lambdas instead")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreValidated<id, id> *(^)(PresenterBaseArrow_coreValidated<id, id> *))liftFl:(id _Nullable (^)(id _Nullable))fl fr:(id _Nullable (^)(id _Nullable))fr __attribute__((swift_name("lift(fl:fr:)"))) __attribute__((deprecated("Validated functionality is being merged into Either, but this API is niche and will be removed in the future. If this method is crucial for you, please let us know on the Arrow Github. Thanks!\n https://github.com/arrow-kt/arrow/issues\nPrefer creating explicit lambdas instead")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreValidated<NSArray<id> *, id> *)validNelA:(id _Nullable)a __attribute__((swift_name("validNel(a:)"))) __attribute__((deprecated("Validated functionality is being merged into Either.\nUse right instead to construct the equivalent Either value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Arrow_coreEvalCompanion")))
@interface PresenterBaseArrow_coreEvalCompanion : PresenterBaseBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) PresenterBaseArrow_coreEvalCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreEvalAlways<id> *)alwaysF:(id _Nullable (^)(void))f __attribute__((swift_name("always(f:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreEval<id> *)deferF:(PresenterBaseArrow_coreEval<id> *(^)(void))f __attribute__((swift_name("defer(f:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreEvalLater<id> *)laterF:(id _Nullable (^)(void))f __attribute__((swift_name("later(f:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreEval<id> *)nowA:(id _Nullable)a __attribute__((swift_name("now(a:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (PresenterBaseArrow_coreEval<PresenterBaseKotlinNothing *> *)raiseT:(PresenterBaseKotlinThrowable *)t __attribute__((swift_name("raise(t:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Arrow_coreEvalAlways")))
@interface PresenterBaseArrow_coreEvalAlways<__covariant A> : PresenterBaseArrow_coreEval<A>
- (instancetype)initWithF:(A _Nullable (^)(void))f __attribute__((swift_name("init(f:)"))) __attribute__((objc_designated_initializer));
- (PresenterBaseArrow_coreEvalAlways<A> *)doCopyF:(A _Nullable (^)(void))f __attribute__((swift_name("doCopy(f:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (PresenterBaseArrow_coreEval<A> *)memoize __attribute__((swift_name("memoize()")));
- (NSString *)description __attribute__((swift_name("description()")));
- (A _Nullable)value __attribute__((swift_name("value()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Arrow_coreEvalLater")))
@interface PresenterBaseArrow_coreEvalLater<__covariant A> : PresenterBaseArrow_coreEval<A>
- (instancetype)initWithF:(A _Nullable (^)(void))f __attribute__((swift_name("init(f:)"))) __attribute__((objc_designated_initializer));
- (PresenterBaseArrow_coreEvalLater<A> *)doCopyF:(A _Nullable (^)(void))f __attribute__((swift_name("doCopy(f:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (PresenterBaseArrow_coreEval<A> *)memoize __attribute__((swift_name("memoize()")));
- (NSString *)description __attribute__((swift_name("description()")));
- (A _Nullable)value __attribute__((swift_name("value()")));
@property (readonly, getter=value_) A _Nullable value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinNothing")))
@interface PresenterBaseKotlinNothing : PresenterBaseBase
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
