## UI Screen Design & Use Case Descriptions

1)상품 검색, 검색 결과 상품 리스트 정렬 기준  '평균 구매만족도'로 변경
<img width="612" alt="image" src="https://user-images.githubusercontent.com/87361140/166112023-c9fb9c0c-5261-4aa4-85a1-bb43b181fc0d.jpeg">
|Actor Action|System Response|
|---|---|
||1. 검색 화면을 출력한다.|
|2. 회원이 검색어를 입력한다.|3. 검색어에 해당하는 상품 리스트를 상품명의 오름차순으로 출력한다.|
|4. 검색 조건을 '평균 구매 만족도'로 변경한다.|5. 상품 리스트를 평균 구매 만족도가 높은 순서로 출력한다.|
|Alternative Cources
Step4-5는 검색 조건이 '상품명'이길 원하는 경우 생략할 수 있다.|

2)상품 상세 정보 조회
<img width="612" alt="image" src="https://user-images.githubusercontent.com/87361140/166112105-3d496b26-7128-4797-b421-7594b1d0d773.jpeg">
|Actor Action|System Response|
|---|---|
||1. 상품 리스트를 출력한다.|
|2. 상세 정보가 보고싶은 상품을 선택한다.|3. 선택한 상품의 상세 정보를 출력한다.|

3)상품 구매, 추가 상품 구매, 포인트 사용
<img width="612" alt="image" src="https://user-images.githubusercontent.com/87361140/166112153-46018f14-e61f-4171-b786-f3e9ce7aee57.jpeg">
|Actor Action|System Response|
|---|---|
||1. 상품 리스트를 출력한다.|
|2. 회원이 구매를 원하는 상품을 선택한다.|3. 선택한 상품의 상세한 정보를 출력한다.|
|5. 추가 상품으로 등록한 물품도 같이 선택한다.|6. 추가 상품 금액만큼 증가된 총 구매금액을 출력한다.|
|7. '즉시 구매'버튼을 클릭한다.|8. 결제할 내역을 출력한다.|
|9. 사용할 포인트를 입력한다.|10. 회원이 입력한 포인트를 뺀 최종 결제 금액을 출력한다.|
|11. 결제를 진행한다.|12. 구매가 완료되었다는 메세지를 출력한다.|
|Alternative Cources
Step5-6은 추가 상품을 구매할 필요가 없다면 생략할 수 있다.|
|Step9-10은 포인트가 3000점이 넘지 않거나 포인트를 사용하지 않을 경우 생략할 수 있다.|

4) 포인트 적립 기능

4-1) 포인트 적립
<img width="512" alt="image" src="https://user-images.githubusercontent.com/87361140/166112367-3b39ee32-9851-477b-9fa9-64538876d265.jpeg">
|Actor Action|System Response|
|---|---|
|1. 회원이 상품을 구매하는 Event가 발생한다.|2. 구매가 완료되었다는 메세지를 띄우면서 적립된 포인트도 함께 출력한다.|

4-2) 포인트 반환
<img width="612" alt="image" src="https://user-images.githubusercontent.com/87361140/166112073-c0fa10af-a142-4b7e-b344-1648e517d703.jpeg">
|Actor Action|System Response|
|---|---|
|1. 회원이 신청한 환불이 완료된다.| |
||2. 상품 구매 내역 페이지를 출력한다.|
|3. 환불된 상품을 선택한다.|4. 반환된 포인트를 포함한 환불 내역 정보를 출력한다.|
