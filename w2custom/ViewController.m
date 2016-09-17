//
//  ViewController.m
//  w2custom
//
//  Created by mac on 8/15/16.
//  Copyright © 2016 Myth. All rights reserved.
//

#import "ViewController.h"
#import "W2PaymentView.h"

@interface ViewController ()<W2PaymentViewDelegate, UIAlertViewDelegate>

@property(nonatomic, strong)W2PaymentView *paymentView;
@property(nonatomic, strong)NSArray *arrCellSetup;
@property(nonatomic, strong)NSMutableArray *arrAddress;
@property(nonatomic, strong)NSMutableArray *arrCard;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.paymentView = [[W2PaymentView alloc]init];
    self.paymentView.frame = [UIScreen mainScreen].bounds;
    self.paymentView.delegate = self;
    self.paymentView.useThirdPartyPayment = NO;
    [self.view addSubview:self.paymentView];
    [self cellSetUp];
    _arrAddress = [[NSMutableArray alloc]init];
    _arrCard = [[NSMutableArray alloc]init];
    [self.paymentView reloadData];
    // Do any additional setup after loading the view, typically from a nib.
}

-(void)cellSetUp
{
    W2PaymentCellFormatter *addressCell = [[W2PaymentCellFormatter alloc]init];
    addressCell.cellTitle = @"Ship To";
    addressCell.cellPlaceHolder = @"Address";
    addressCell.cellType = W2PaymentCellAddress;
    
    W2PaymentCellFormatter *creditCardCell = [[W2PaymentCellFormatter alloc]init];
    creditCardCell.cellTitle = @"Payment";
    creditCardCell.cellPlaceHolder = @"Credit Card";
    creditCardCell.cellType = W2PaymentCellPayment;
    
    W2PaymentCellFormatter *promoCell = [[W2PaymentCellFormatter alloc]init];
    promoCell.cellType = W2PaymentCellEnterText;
    promoCell.cellTitle = @"Promo";
    promoCell.cellPlaceHolder = @"enter code";
    
    W2PaymentCellFormatter *totalCell = [[W2PaymentCellFormatter alloc]init];
    totalCell.cellType = W2PaymentCellDefault;
    totalCell.cellTitle = @"Total";
    totalCell.cellPlaceHolder = @"$0.00";
    
    W2PaymentCellFormatter *swipeCell = [[W2PaymentCellFormatter alloc]init];
    swipeCell.cellType = W2PaymentCellSwipe;
    
    self.arrCellSetup = @[addressCell,creditCardCell, promoCell, totalCell, swipeCell];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - W2PaymentDelegate

-(NSUInteger)numberOfCellInPayment
{
    return self.arrCellSetup.count;
}

-(PaymentCell*)paymentView:(W2PaymentView *)payment cellForContentAtIndex:(NSInteger)index
{
    PaymentCell *cell = [payment cellWithFormatterObject:[self.arrCellSetup objectAtIndex:index]];
    return cell;
}

-(NSString*)paymentView:(W2PaymentView *)payment contentForCellAtIndex:(NSInteger)index
{
    if(index == 3)
        return @"$123.00";
    return @"";
}

-(void)actionForPaymentCellAtIndex:(NSInteger)index
{
    //OutletAction
}

-(void)getDataFromServer
{
    //GetData: Card , Address , Other
}

-(void)postPayment
{
    UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"" message:@"Confirm?" delegate:self cancelButtonTitle:@"Cancel" otherButtonTitles: nil];
    [alert show];
}

-(void)addCreditCard:(CreditCardObject *)obj
{
    [_arrCard addObject:obj];
    [self.paymentView setCreditCardArray:_arrCard andSelectedIndex:0];
}

-(void)addAddress:(AddressObject *)obj
{
    [_arrAddress addObject:obj];
    [self.paymentView setAddressArray:_arrAddress andSelectedIndex:0];
}


-(void)paymentView:(W2PaymentView *)payment didEnterText:(NSString *)text forCellAtIndex:(NSInteger)index
{
    //Use if you have a cell need enter text such as promo code
}

-(void)thirdPartyPaymentDidChoose
{
    
}

-(void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    [self.view endEditing:YES];
    [self.paymentView swipeCellSwipeBack];
}

@end
