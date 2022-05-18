## 1. 상품 정보 검색 기능

## 📌 Use Case Diagram

<img width="577" alt="search_product_use_case_diagram" src="https://user-images.githubusercontent.com/62105312/168429528-93297ac8-aaf3-42c0-a818-276dc8ee429e.png">

## 📌 Use Case Description

| Actor Action                         | System Response                                                                                               |
| ------------------------------------ | ------------------------------------------------------------------------------------------------------------- |
| 1. 회원이 검색어(상품명)를 입력한다. | 2. 검색어에 해당하는 상품 리스트(판매자 ID, 상품명, 제작회사명, 가격, 남은 수량, 평균 구매만족도)를 보여준다. |

## 📌 Communication Diagram

<img width="641" alt="search_product_communication_diagram" src="https://user-images.githubusercontent.com/62105312/168778552-b5d365d7-71fb-4b00-ad8d-6c9e006573a3.png">

## 📌 Use Case Class Diagram

<img width="590" alt="search_product_class_diagram" src="https://user-images.githubusercontent.com/62105312/168778529-d288e6f5-a97c-4a3c-8d07-2e0e2cea79b4.png">

## 2. 상품 구매 기능

## 📌 Use Case Diagram

<img width="577" alt="purchase_product_use_case_diagram" src="https://user-images.githubusercontent.com/62105312/168451923-6304d35d-ba01-4ad5-bb2f-e604e39f6cce.png">

## 📌 Use Case Description

| Actor Action                                    | System Response                                                                                               |
| ----------------------------------------------- | ------------------------------------------------------------------------------------------------------------- |
| 1. 회원이 검색어(상품명)을 입력한다.            | 2. 검색어에 해당하는 상품 리스트(판매자 ID, 상품명, 제작회사명, 가격, 남은 수량, 평균 구매만족도)를 보여준다. |
| 3. 구매자가 구매를 원하는 상품을 즉시 구매한다. |                                                                                                               |

## 📌 Communication Diagram

<img width="641" alt="purchase_product_communication_diagram" src="https://user-images.githubusercontent.com/62105312/169061505-1c3c0ced-76bc-417a-86c6-34fd4d6e0026.png">

## 📌 Use Case Class Diagram

<img width="590" alt="purchase_product_class_diagram" src="https://user-images.githubusercontent.com/62105312/169075586-e8dc568f-4a8b-481c-9de3-2eb40a618baf.png">

## 3. 구매 내역 조회 기능

## 📌 Use Case Diagram

<img width="577" alt="check_purchase_list_use_case_diagram" src="https://user-images.githubusercontent.com/62105312/168620104-1794524f-de5e-41e6-8ed5-4c5454c3ecb1.png">

## 📌 Use Case Description

| Actor Action                 | System Response                                            |
| ---------------------------- | ---------------------------------------------------------- |
| 1. 구매 내역 조회를 클릭한다 | 2. 해당 회원의 구매 내역을 상품명의 오름차순으로 출력한다. |

## 📌 Communication Diagram

<img width="641" alt="check_purchased_list_communication_diagram" src="https://user-images.githubusercontent.com/62105312/169038524-da174ed9-a444-4f68-8709-08c8947914ff.png">

## 📌 Use Case Class Diagram

<img width="590" alt="check_purchased_list_class_diagram" src="https://user-images.githubusercontent.com/62105312/169042486-d925e61d-6077-4217-842f-03311405e765.png">

## 4. 구매만족도 평가 기능

## 📌 Use Case Diagram

<img width="577" alt="evaluate_rating_list_use_case_diagram" src="https://user-images.githubusercontent.com/62105312/168453108-6fc376f6-ccf7-45c4-bb81-16361d3e873c.png">

## 📌 Use Case Description

| Actor Action                               | System Response                                   |
| ------------------------------------------ | ------------------------------------------------- |
| 1. 구매 내역에서 한 상품을 선택한다.       | 2. 선택된 상품의 구매만족도 평가 화면을 보여준다. |
| 3. 구매 만족도로 1~5 사이의 값을 선택한다. |                                                   |

## 📌 Communication Diagram

<img width="641" alt="evaluate_rating_communication_diagram" src="https://user-images.githubusercontent.com/62105312/168723427-3ad29930-c666-4903-8a4d-36cdd249df49.png">

## 📌 Use Case Class Diagram

<img width="590" alt="evaluate_rating_list_class_diagram" src="https://user-images.githubusercontent.com/62105312/168723430-dd5fe180-cc9c-4d7b-941f-57853cba6517.png">
