import torch.nn as nn
import torch.nn.functional as F
import torch

class MyNet4(nn.Module):
    def __init__(self):
        super(MyNet4, self).__init__()
        self.conv1 = nn.Sequential(
            nn.Conv2d(in_channels=1, out_channels=3, kernel_size=(15, 1), stride=(2, 1), padding=0),
            nn.ReLU(True),
            nn.BatchNorm2d(3, affine=True, track_running_stats=True, eps=1e-5, momentum=0.1),
        )

        self.conv2 = nn.Sequential(
            nn.Conv2d(in_channels=3, out_channels=3, kernel_size=(7, 1), stride=(2, 1), padding=0),
            nn.ReLU(True),
            nn.BatchNorm2d(3, affine=True, track_running_stats=True, eps=1e-5, momentum=0.1),
        )

        # self.conv3 = nn.Sequential(
        #     nn.Conv2d(in_channels=3, out_channels=5, kernel_size=(5, 1), stride=(2, 1), padding=0),
        #     nn.ReLU(True),
        #     nn.BatchNorm2d(5, affine=True, track_running_stats=True, eps=1e-5, momentum=0.1),
        # )

        self.fc1 = nn.Sequential(
            nn.Flatten(),
            nn.Dropout(0.5),
            nn.Linear(in_features=918, out_features=2),
        )
        # self.fc2 = nn.Sequential(
        #     nn.Dropout(0.5),
        #     nn.Linear(in_features=10, out_features=2)
        # )

    def forward(self, input):
        x = self.conv1(input)
        x = self.conv2(x)
        # x = self.conv3(x)
        x = self.fc1(x)
        # x = self.fc2(x)


        return x

# i = torch.ones((32,1,1250,1))
# model = MyNet4()
# o = model(i)
# print(o)


