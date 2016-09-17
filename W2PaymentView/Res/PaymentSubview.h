//
//  PaymentSubview.h
//  CustomPaymentView
//
//  Created by mac on 8/3/16.
//  Copyright © 2016 Myth. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AddressObject.h"
#import "CreditCardObject.h"
@protocol PaymentSubviewDelegate <NSObject>

-(void)showKeyboard:(BOOL)show;
-(void)subContentDidChange;
-(void)didEditText;
-(void)didEndEditText;
-(void)reloadData;
-(void)setDynamicData:(NSString*)data forKey:(NSString*)key;
-(void)addAddress:(AddressObject*)obj;
-(void)addCreditCard:(CreditCardObject*)obj;
-(void)thirdPartyPaymentDidChoose;
-(void)creditCardDidChoose;

@end

@interface PaymentSubview : UIView

@property(nonatomic)id<PaymentSubviewDelegate> delegate;
@property(nonatomic, strong, setter=setDoneButtonTitle:)NSString *doneButtonTitle;
@property(nonatomic, strong, setter=setAddCardButtonTitle:)NSString *addCardButtonTitle;
@property(nonatomic, strong, setter=setAddAddressButtonTitle:)NSString *addAddressButtonTitle;
-(void)fillData:(NSDictionary*)dictData;

@end
