//
//  W2PaymentView.h
//  CustomPaymentView
//
//  Created by mac on 8/3/16.
//  Copyright © 2016 Myth. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PaymentCell.h"
#import "PaymentSubview.h"
#import "W2PaymentCellFormatter.h"
#import "AddressObject.h"
#import "CreditCardObject.h"

@class W2PaymentView;
@protocol W2PaymentViewDelegate <NSObject>

-(NSUInteger)numberOfCellInPayment;
-(PaymentCell*)paymentView:(W2PaymentView*)payment cellForContentAtIndex:(NSInteger)index;

@optional

-(void)actionForPaymentCellAtIndex:(NSInteger)index;
-(void)getDataFromServer;
-(PaymentSubview*)paymentView:(W2PaymentView*)payment subContentForCellAtIndex:(NSInteger)index;
-(void)postPayment;
-(void)addAddress:(AddressObject*)obj;
-(void)addCreditCard:(CreditCardObject*)obj;
-(void)paymentView:(W2PaymentView*)payment didEnterText:(NSString*)text forCellAtIndex:(NSInteger)index ;
-(NSString*)paymentView:(W2PaymentView*)payment contentForCellAtIndex:(NSInteger)index;
-(void)thirdPartyPaymentDidChoose;

@end

@interface W2PaymentView : UIView<PaymentCellDelegate, PaymentSubviewDelegate, UIScrollViewDelegate>

@property(nonatomic)id<W2PaymentViewDelegate> delegate;
@property(nonatomic, strong)NSMutableDictionary *dynamicData;
@property(nonatomic)BOOL useThirdPartyPayment;

-(void)reloadData;
-(PaymentCell*)cellWithFormatterObject:(W2PaymentCellFormatter*)obj;
-(void)setCreditCardArray:(NSArray*)arr andSelectedIndex:(NSInteger)index;
-(void)setAddressArray:(NSArray*)arr andSelectedIndex:(NSInteger)index;
-(AddressObject*)selectedAddress;
-(CreditCardObject*)selectedCard;
-(void)thirdPartyPaymentDidLoginSuccess;
-(void)swipeCellSwipeBack;

+(void)initW2PaymentEnvironment;

#pragma mark - Button Title and Placeholder

@property(nonatomic, strong)NSString *swipeCellTitle;
@property(nonatomic, strong)NSString *doneButtonTitle;
@property(nonatomic, strong)NSString *addCardButtonTitle;
@property(nonatomic, strong)NSString *addAddressButtonTitle;
@property(nonatomic, strong)NSString *changeBillingAddressButtonTitle;
@property(nonatomic, strong)NSString *cancelChangeBillingButtonTitle;
@property(nonatomic, strong)NSString *namePlaceholder;
@property(nonatomic, strong)NSString *streetPlaceholder;
@property(nonatomic, strong)NSString *statePlaceholder;
@property(nonatomic, strong)NSString *zipCodePlaceholder;
@property(nonatomic, strong)NSString *cityPlaceholder;
@property(nonatomic, strong)NSString *phonePlaceholder;
@property(nonatomic, strong)NSString *cardNumberPlaceholder;
@property(nonatomic, strong)NSString *cvcPlaceholder;
@property(nonatomic, strong)NSString *expirePlaceholder;

@end
