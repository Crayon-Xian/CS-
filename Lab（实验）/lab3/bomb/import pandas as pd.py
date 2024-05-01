import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("data.csv")
grouped_data = data.groupby(["Size", "Order"]).mean().reset_index()

fig, ax = plt.subplots()
for order in ["ipj", "ijp", "jip", "jpi", "pij", "pji"]:
    order_data = grouped_data[grouped_data["Order"] == order]
    ax.plot(order_data["Size"], order_data["GFLOPS"], label=order)
    ax.scatter(order_data["Size"], order_data["GFLOPS"])

ax.set_xlabel("Matrix Size")
ax.set_ylabel("GFLOPS")
ax.legend()
plt.show()
